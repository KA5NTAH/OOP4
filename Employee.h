#pragma once
#include <string>
#include "Date.h"


class Employee 
{
protected:
	// static default values
	static int employee_counter;
	static std::string no_str_info;
	static char no_init_letter_info;
	static int no_department_info;
	static Date dummy_date;


	std::string first_name;
	std::string family_name;
	char middle_name_init_letter;
	Date hiring_date;
	bool valid_date;
	short int department;
	void print_general_info(const std::string indent) const;
public:
	// constructors
	Employee();
	Employee(const std::string& fname,const short int& department);
	Employee(const std::string& fnam,const char& mid_name,const std::string& fam_nam,const Date& hir_date,const short int& dep);
	virtual void print_info(const std::string indent="") const;
	static int get_empl_counter();
	virtual ~Employee();
};

