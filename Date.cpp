#include "Date.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>


bool Date::LeapChecker(int y) {
	bool div_by_4 = y % 4 == 0;
	bool div_by_100 = y % 100 == 0;
	bool div_by_400 = y % 400 == 0;
	return div_by_4 and (div_by_400 or not div_by_100);
}


Date& Date::operator=(const Date& rhs) {
	if (this != &rhs) {
		this->year = rhs.year;
		this->month = rhs.month;
		this->day = rhs.day;
		this->leap = rhs.leap;
		this->days_per_month = rhs.days_per_month;
	}
	return *this;
}


void Date::SetMonthAndDayByDayNumber(int day_number, std::vector<int>& cumsum) {
	// cumsum[i] = month_len[i] + month_len[i - 1] + ... + month_len[0]
	// |------|------|------|------|--#---|------|
	auto month_end = std::lower_bound(cumsum.begin(), cumsum.end(), day_number);
	this->month = std::distance(cumsum.begin(), month_end);
	auto previous_month_end = --month_end;
	this->day = day_number - *previous_month_end;
}


Date& Date::operator+=(int days_to_add) {
	if (this->day + days_to_add <= days_per_month[this->month]) this->day += days_to_add;
	else {
		std::vector<int> cumsum(days_per_month.size(), 0);
		while (days_to_add > 0) {
			// достаточно ли дней прибавляется чтобы перейти на первый день следующего года
			// анализируем текущий год				
			bool curr_leap = LeapChecker(this->year);
			std::vector<int>curr_dpm = curr_leap ? this->leap_dpm : this->standart_dpm;
			int curr_ylen = curr_leap ? this->leap_year_length : this->standart_year_length;
			//
			std::partial_sum(curr_dpm.begin(), curr_dpm.end(), cumsum.begin());  // i элемент - сколько дней от начала года до конца i месяца
			int curr_day_number = cumsum[this->month - 1] + this->day;
			if (curr_day_number + days_to_add > curr_ylen) {
				// переход в начало следующего года
				this->year += 1;
				this->month = 1;
				this->day = 1;
				int skipped_days = curr_ylen - curr_day_number + 1;
				days_to_add -= skipped_days;
			}
			else {
				SetMonthAndDayByDayNumber(curr_day_number + days_to_add, cumsum);
				days_to_add = 0;
			}
		}
	}
	return *this;
}


Date& Date::operator-=(int days_to_subtract) {
	if (this->day - days_to_subtract >= 1) this->day -= days_to_subtract;
	else {
		std::vector<int> cumsum(days_per_month.size(), 0);
		while (days_to_subtract > 0) {
			// анализируем текущий год			
			bool curr_leap = LeapChecker(this->year);
			int curr_ylen = curr_leap ? leap_year_length : standart_year_length;
			std::vector<int> curr_dpm = curr_leap ? leap_dpm : standart_dpm;
			//
			std::partial_sum(curr_dpm.begin(), curr_dpm.end(), cumsum.begin());  // i элемент - сколько дней от начала года до конца i 
			int curr_day_number = cumsum[this->month - 1] + this->day;
			// проверка выхода за границы года
			if (curr_day_number - days_to_subtract <= 0) {
				// переход в конец предыдущего года				
				this->year -= 1;
				this->month = this->months_number;
				this->day = this->days_per_month[month];
				int skipped_days = curr_day_number;
				days_to_subtract -= skipped_days;
			}
			else {
				SetMonthAndDayByDayNumber(curr_day_number - days_to_subtract, cumsum);
				days_to_subtract = 0;
			}
		}
	}
	return *this;
}


const Date Date::operator+(int days_to_add) {
	Date result = *this;
	result += days_to_add;
	return result;
}


Date Date::operator-(int days_to_subtract) {
	Date result = *this;
	result -= days_to_subtract;
	return result;
}


std::ostream& operator<<(std::ostream& out, const Date& d) {
	std::string day_format = d.day >= 10 ? std::to_string(d.day) : "0" + std::to_string(d.day);
	std::string month_format = d.month >= 10 ? std::to_string(d.month) : "0" + std::to_string(d.month);
	out << day_format << "." << month_format << "." << d.year << "\n";
	return out;
}


std::istream& operator>>(std::istream& in, Date& d) {
	in >> d.year >> d.month >> d.day;
	return in;
}


bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.year < rhs.year) return true;
	if (lhs.year > rhs.year) return false;
	if (lhs.month < rhs.month) return true;
	if (lhs.month > rhs.month) return false;
	if (lhs.day < rhs.day) return true;
	if (lhs.day > rhs.day) return false;
}


bool operator>(const Date& lhs, const Date& rhs) {
	if (lhs.year < rhs.year) return false;
	if (lhs.year > rhs.year) return true;
	if (lhs.month < rhs.month) return false;
	if (lhs.month > rhs.month) return true;
	if (lhs.day < rhs.day) return false;
	if (lhs.day > rhs.day) return true;
}


bool Date::operator==(const Date& rhs) const {
	return *this < rhs and *this > rhs;
}


bool Date::operator!=(const Date& rhs) const {
	return not(*this == rhs);
}


Date& Date::operator++() {
	*this += 1;
	return *this;
}


Date Date::operator++(int) {
	Date tmp = *this;
	++(*this);
	return tmp;
}


Date& Date::operator--() {
	*this -= 1;
	return *this;
}


Date Date::operator--(int) {
	Date tmp = *this;
	--(*this);
	return tmp;
}


void Date::edit_years(int years_correction) {
	this->year += years_correction;
	this->year = std::max(0, this->year);
}

void Date::edit_month(int m_correction) {
	int years_change = m_correction / this->months_number;
	m_correction -= years_change * this->months_number;
	if (m_correction > 0) {
		this->year += years_change;
		this->month += m_correction;
		if (this->month > this->months_number) {
			this->year += 1;
			this->month -= months_number;
		}
	}
	else {
		this->year += years_change;
		this->month += m_correction;
		if (this->month <= 0) {
			this->year -= 1;
			this->month = this->months_number - this->month;
		}
	}
}


void Date::edit_day(int d_correction) {
	if (d_correction >= 0) (*this) += d_correction;
	else (*this) -= d_correction;
}
