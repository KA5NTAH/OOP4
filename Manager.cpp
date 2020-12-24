#include "Manager.h"
#include "DesignRules.h"

using namespace std;
int Manager::manager_counter = 0;

Manager::Manager() : Employee::Employee() {
	Manager::manager_counter++;
	this->level = -1;
	this->group = {};
}

Manager::Manager(const std::string& fname, const short int& dep, const short int& lvl) : Manager::Manager() {
	this->first_name = fname;
	this->department = dep;
	this->level = lvl;
}

Manager::Manager(const std::string& fnam, const char& mid_name, const std::string& fam_nam, const Date& hir_date,
	const short int& dep, const std::set<Employee*>& group, const short int& lvl) : Manager::Manager(fnam, dep, lvl)
{
	this->valid_date = true;
	this->family_name = fam_nam;
	this->middle_name_init_letter = mid_name;
	this->hiring_date = hir_date;
	this->group = group;
}


int Manager::get_manager_counter() {
	return Manager::manager_counter;
}


void Manager::print_manager_info(const std::string& indent) const {
	this->print_general_info(indent);
	if (this->group.size() == 0)  cout << indent << "No suboridnates\n";
	else {
		cout << indent << "Subordinates:\n";
		string nested_indent = indent + info_indent;		
		int sub_count = 1;
		for (auto sub : this->group) {
			cout << nested_indent << "Subordinate " << sub_count << "\n";
			sub->print_info(nested_indent);
			sub_count++;
		}
	}
}

void Manager::print_info(const std::string indent) const {
	cout << indent << "Manger info:\n";
	this->print_manager_info(indent + info_indent);
}


Manager::~Manager() {
	Manager::manager_counter--;
}