#include "Director.h"
#include "DesignRules.h"

using namespace std;
int Director::director_counter = 0;

Director::Director() : Manager() {
	Director::director_counter++;
	this->years_of_service = -1;
}


Director::Director(const std::string& fnam, const short int& dep, const short int& lvl) : Director() {
	this->first_name = fnam;
	this->department = dep;
	this->level = lvl;
}


Director::Director(const std::string& fnam, const char& mid_name, const std::string& fam_nam,
	const Date& hir_date, const short int& dep, const std::set<Employee*>& group,
	const short int& lvl, const short int& years_of_service) : Director(fnam, dep, lvl) 
{
	this->valid_date = true;
	this->family_name = fam_nam;
	this->middle_name_init_letter = mid_name;
	this->hiring_date = hir_date;
	this->group = group;
	this->years_of_service = years_of_service;
}


void Director::print_info(string indent) const {
	cout << indent << "Director info:\n";
	this->print_manager_info(indent + info_indent);
	cout << indent + info_indent << "Years of service = " << years_of_service << "\n\n";
}


int Director::get_director_counter() {
	return Director::director_counter;
}


Director::~Director() {
	Director::director_counter--;
}