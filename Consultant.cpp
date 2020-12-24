#include "Consultant.h"
#include "DesignRules.h"

using namespace std;
int Consultant::consultant_counter = 0;


Consultant::Consultant() : Temporary::Temporary() {
	this->consul_rating = -1;
}


Consultant::Consultant(const std::string& fname, const std::string& fam_nam, const Date& beg, const Date& end, const int& rate) 
	: Temporary(fname, fam_nam, beg, end)
{
	Consultant::consultant_counter++;
	this->consul_rating = rate;
	this->begin_date_is_known = true;
	this->end_date_is_known = true;
}


int Consultant::get_consultant_counter() {
	return Consultant::consultant_counter;
}


void Consultant::print_consultant_info(const std::string& indent) const{
	this->print_tmp_general_info(indent);
	cout << indent << "Consulting rating - " << this->consul_rating << "\n";
}


void Consultant::print_tmp_info(const std::string indent) const {
	cout << indent << "Temporary Consultant info:\n";
	this->print_consultant_info(indent + info_indent);
}


Consultant::~Consultant() {
	Consultant::consultant_counter--;
}
