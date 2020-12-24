#pragma once
#include <string>
#include <set>
#include "Employee.h"
#include "Date.h"

class Manager : public Employee
{
protected:
	static int manager_counter;
	short int level;
	std::set<Employee*> group;
	void print_manager_info(const std::string& indent) const;
public:
	Manager();
	Manager(const std::string& fname, const short int& dep, const short int& lvl);
	Manager(const std::string& fnam, const char& mid_name, const std::string& fam_nam,
		const Date& hir_date, const short int& dep, const std::set<Employee*>& group, const short int& lvl);
	static int get_manager_counter();
	void print_info(const std::string indent="") const override;
	virtual ~Manager();
};

