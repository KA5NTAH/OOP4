#pragma once
#include "Manager.h"


class Director : public Manager
{
protected:
	static int director_counter;
	int years_of_service;

public:
	Director();
	Director(const std::string& fnam, const short int& dep, const short int& lvl);
	Director(const std::string& fnam, const char& mid_name, const std::string& fam_nam,
		const Date& hir_date, const short int& dep, const std::set<Employee*>& group,
		const short int& lvl, const short int &years_of_service);
	
	virtual void print_info(std::string indent="") const;
	static int get_director_counter();
	virtual ~Director();
};

