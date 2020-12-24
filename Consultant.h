#pragma once
#include <string>
#include "Temporary.h"

class Consultant : public Temporary
{
protected:
	static int consultant_counter;
	void print_consultant_info(const std::string& indent) const;
	int consul_rating;
public:
	Consultant();
	Consultant(const std::string& fname, const std::string& fam_nam, const Date& beg, const Date& end, const int& rate);
	static int get_consultant_counter();
	virtual void print_tmp_info(const std::string indent = "") const;
	virtual ~Consultant();
};

