#include "Secretary.h"
#include "DesignRules.h"
using namespace std;

int Secretary::secretary_counter = 0;

Secretary::Secretary() : Employee() {
	secretary_counter++;
	this->eng_knowledge = false;
}

Secretary::Secretary(const string& fname,const short int& department) : Secretary::Secretary()
{
	this->first_name = fname;
	this->department = department;
}

Secretary::Secretary(const std::string& fnam, const char& mid_name, const std::string& fam_nam, const Date& hir_date, const short int& dep, const bool& eng_knowledge) :
	Secretary::Secretary(fnam, dep)
{
	this->valid_date = true;
	this->family_name = fam_nam;
	this->middle_name_init_letter = mid_name;
	this->hiring_date = hir_date;
	this->eng_knowledge = eng_knowledge;
}


void Secretary::print_secretary_info(const std::string& indent) const {
	this->print_general_info(indent);
	string eng_info = this->eng_knowledge ? "yes\n" : "no\n";
	cout << indent << "English knowledge - " << eng_info;
}

void Secretary::print_info(const std::string indent) const {
	cout << indent << "Secretary_info\n";
	this->print_secretary_info(indent + info_indent);
	cout << "\n";
}

int Secretary::get_secretary_counter() {
	return Secretary::secretary_counter;
}

Secretary::~Secretary() {
	Secretary::secretary_counter--;
}