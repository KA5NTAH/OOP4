#pragma once
# include <string>
# include "Date.h"


class Temporary
{
protected:
	std::string first_name, family_name;
	Date begin, end;
	bool begin_date_is_known, end_date_is_known;
	static int temp_counter;
	void print_tmp_general_info(const std::string& indent) const;
public:
	Temporary();
	Temporary(const std::string& fnam, const std::string& fam_nam, const Date& beg, const Date& end);
	Temporary(const Date& beg, const Date& end);
	static int get_temporary_counter();
	virtual void print_tmp_info(const std::string indent = "") const;
	virtual ~Temporary();
};

