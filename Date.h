#pragma once
#include <vector>
#include <numeric>
#include <iostream>

class Date
{
public:
	// названи€ мес€цев
	const static int jan = 1;
	const static int feb = 2;
	const static int mar = 3;
	const static int apr = 4;
	const static int may = 5;
	const static int jun = 6;
	const static int jul = 7;
	const static int aug = 8;
	const static int sep = 9;
	const static int oct = 10;
	const static int nov = 11;
	const static int dec = 12;


	// конструкторы
	Date() {
		year = default_y;
		month = default_m;
		day = default_d;
		leap = LeapChecker(year);
		days_per_month = leap ? leap_dpm : standart_dpm;
		days_in_year = leap ? leap_year_length : standart_year_length;
	};

	Date(int y) {
		month = this->default_m;
		day = this->default_d;
		if (y > 0) year = y;
		else {
			year = default_y;
			std::cout << "Invalud year value. Default was used.\n";
		}
		leap = LeapChecker(year);
		days_per_month = leap ? leap_dpm : standart_dpm;
		days_in_year = leap ? leap_year_length : standart_year_length;
	};

	Date(int y, int m) : Date(y) {
		if (m > 0 and m <= months_number) month = m;
		else {
			month = default_m;
			std::cout << "Invalid month value. Default was used.\n";
		}
	};

	Date(int y, int m, int d) : Date(y, m) {
		if (d > 0 and d <= days_per_month[month]) day = d;
		else {
			day = default_d;
			std::cout << "Invalud day value. Default was used.\n";
		}
	};

	Date(const Date& to_copy) {
		this->year = to_copy.year;
		this->month = to_copy.month;
		this->day = to_copy.day;
		this->leap = to_copy.leap;
		this->days_per_month = to_copy.days_per_month;
		this->days_in_year = to_copy.days_in_year;
	}

	~Date() {
	};

	// перегруженные операторы
	Date& operator=(const Date& rhs);

	Date& operator+=(int days_to_add);

	Date& operator-=(int days_to_substract);

	const Date operator+(int days_to_add);

	Date operator-(int days_to_subtract);

	friend std::ostream& operator<<(std::ostream& out, const Date& d);

	friend std::istream& operator>>(std::istream& in, Date& d);

	friend bool operator<(const Date& lhs, const Date& rhs);

	friend bool operator>(const Date& lhs, const Date& rhs);

	bool operator==(const Date& rhs) const;

	bool operator!=(const Date& rhs) const;

	Date& operator++(); // префикс

	Date operator++(int); // постфикс

	Date& operator--();

	Date operator--(int);

	// константые функции члены дл€ запросов
	int get_year() const { return this->year; }

	int get_month() const { return this->month; }

	int get_day() const { return this->day; }


	// функции изменени€ даты на целое количество лет, мес€цев, дней
	void edit_years(int years_number);

	void edit_month(int month_number);

	void edit_day(int days);


private:
	// стандартна€ дата
	const static int default_y = 2000;
	const static int default_m = 1;
	const static int default_d = 1;
	//
	const static int months_number = 12;
	const static int leap_year_length = 366;
	const static int standart_year_length = 365;
	//
	std::vector<int> leap_dpm{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	std::vector<int> standart_dpm{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	std::vector<int> days_per_month;
	int days_in_year;
	int year, month, day;
	int year_length;
	bool leap;

	// приватные методы
	bool LeapChecker(int y);
	void SetMonthAndDayByDayNumber(int day_number, std::vector<int>& cumsum);
};

