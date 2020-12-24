#include "Tsec.h"
#include "DesignRules.h"
using namespace std;

int Tsec::tsec_counter = 0;


Tsec::Tsec() : Temporary::Temporary(), Secretary::Secretary() {
}


Tsec::Tsec(const std::string& fnam, const char& mid_name, const std::string& fam_nam, const Date& hir_date, const short int& dep, const bool& eng_knowledge,
	const Date& end) : Secretary::Secretary(fnam, mid_name, fam_nam, hir_date, dep, eng_knowledge), Temporary::Temporary(fnam, fam_nam, hir_date, end) 
{
	Tsec::tsec_counter++;
	this->begin_date_is_known = true;
	this->end_date_is_known = true;
}


void Tsec::print_tsec_info(const std::string indent) const {
	this->print_secretary_info(indent);
	if (begin_date_is_known) cout << indent << "Begin date - " << this->begin;
	else cout << indent << "Begin date - " << "No info" << "\n";
	if (end_date_is_known) cout << indent << "End date - " << this->end;
	else cout << indent << "End date - " << "No info" << "\n";
}


void Tsec::print_info(const std::string indent) const {
	cout << "Employee Tsec info:\n";
	this->print_tsec_info(indent + info_indent);
}


void Tsec::print_tmp_info(const std::string indent) const {
	cout << "Temporary Tsec info:\n";
	this->print_tsec_info(indent + info_indent);
}

int Tsec::get_tsec_counter() {
	return Tsec::tsec_counter;
}


Tsec::~Tsec() {
	Tsec::tsec_counter--;
}


