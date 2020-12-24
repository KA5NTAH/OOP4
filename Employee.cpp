#include "Employee.h"
#include "Date.h"
#include "DesignRules.h"
using namespace std;

// static init
int Employee::employee_counter = 0;
string Employee::no_str_info = "No info";
char Employee::no_init_letter_info = '-';
int Employee::no_department_info = -1;
Date Employee::dummy_date = Date(2000, 1, 1);

Employee::Employee() {
	Employee::employee_counter++;
	this->first_name = Employee::no_str_info;
	this->family_name = Employee::no_str_info;
	this->hiring_date = Employee::dummy_date;
	this->valid_date = false;
	this->middle_name_init_letter = Employee::no_init_letter_info;
	this->department = Employee::no_department_info;
}

Employee::Employee(const string& fnam,const short int& department) : Employee::Employee() {
	this->first_name = fnam;
	this->department = department;
}

Employee::Employee(const string& fnam, const char& init_letter, const string& fam_name, 
	const Date& h_date,const short int& dep_num) : Employee::Employee(fnam, dep_num)
{
	this->valid_date = true;
	this->family_name = fam_name;
	this->middle_name_init_letter = init_letter;
	this->hiring_date = h_date;
}

int Employee::get_empl_counter()
{
	return Employee::employee_counter;
}

void Employee::print_general_info(const std::string indent) const {
	cout << indent << "Name - " << this->first_name << "\n";
	cout << indent << "Midlle name letter - " << this->middle_name_init_letter << "\n";
	cout << indent << "Family name - " << this->family_name << "\n";
	if (this->valid_date) cout << indent << "Hiring date - " << this->hiring_date;
	else cout << indent << "Hiring date is not known\n";
	cout << indent << "Department - " << this->department << "\n";
}

void Employee::print_info(const std::string indent) const {
	cout << indent << "Employee info:\n";
	this->print_general_info(indent + info_indent);
	cout << "\n";
}

Employee::~Employee() {
	Employee::employee_counter--;
}
