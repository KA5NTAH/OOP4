#pragma once
#include <string>
#include "Employee.h"
#include "Date.h"

class Secretary : public Employee
{
protected:
	static int secretary_counter;
	bool eng_knowledge;
	void print_secretary_info(const std::string& indent) const;
public:
	Secretary();
	Secretary(const std::string& fname, const short int& department);
	Secretary(const std::string& fnam,const char& mid_name,const std::string& fam_nam,const Date& hir_date,const short int& dep, const bool& eng_knowledge);
	static int get_secretary_counter();
	virtual void print_info(const std::string indent="") const;
	virtual ~Secretary();
};

