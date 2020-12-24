#include "Temporary.h"
#include "DesignRules.h"

int Temporary::temp_counter = 0;
using namespace std;


Temporary::Temporary() {
	this->first_name = "No info";
	this->family_name = "No info";
	this->begin_date_is_known = false;
	this->end_date_is_known = false;
	Date dummy;
	this->end = dummy;
	this->begin = dummy;
}


Temporary::Temporary(const std::string& fnam, const std::string& fam_nam, const Date& beg, const Date& end) {
	Temporary::temp_counter++;
	this->begin_date_is_known = true;
	this->end_date_is_known = true;
	this->first_name = fnam;
	this->family_name = fam_nam;
	this->begin = beg;
	this->end = end;
}


Temporary::Temporary(const Date& beg, const Date& end) {
	Temporary::temp_counter++;
	this->begin_date_is_known = true;
	this->end_date_is_known = true;
	this->first_name = "No info";
	this->family_name = "No info";
	this->begin = beg;
	this->end = end;
}


int Temporary::get_temporary_counter() {
	return Temporary::temp_counter;
}

void Temporary::print_tmp_general_info(const std::string& indent) const {
	cout << indent << "First name - " << this->first_name << "\n";
	cout << indent << "Family name - " << this->family_name << "\n";
	if (begin_date_is_known) cout << indent << "Begin date - " << this->begin;
	else cout << indent << "Begin date - " << "No info" << "\n";

	if (end_date_is_known) cout << indent << "End date - " << this->end;
	else cout << indent << "End date - " << "No info" << "\n";
}


void Temporary::print_tmp_info(const std::string indent) const {
	cout << "Temporary Worker info:\n";
	this->print_tmp_general_info(indent + info_indent);
}

Temporary::~Temporary() {
	Temporary::temp_counter--;
}

