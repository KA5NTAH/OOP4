#pragma once
#include "Secretary.h"
#include "Temporary.h"


class Tsec : public Temporary, public Secretary
{
protected:
	static int tsec_counter;
	void print_tsec_info(const std::string indent = "") const;
public:
	Tsec();
	Tsec(const std::string& fnam, const char& mid_name, const std::string& fam_nam, const Date& hir_date, const short int& dep, const bool& eng_knowledge,
		const Date& end);
	static int get_tsec_counter();
	virtual void print_info(const std::string indent = "") const;
	virtual void print_tmp_info(const std::string indent = "") const;
	virtual ~Tsec();
};

