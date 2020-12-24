#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <map>
#include <algorithm>
#include <stack>
#include <map>
#include "Date.h"
#include "Temporary.h"
#include "Employee.h"
#include "Secretary.h"
#include "Manager.h"
#include "Director.h"
#include "Consultant.h"
#include "DesignRules.h"
#include "Tsec.h"


//pair<string, map<string, string>>;
class TextReader
{
private:
	// atributes
	static std::vector<std::string> empl_datatypes; 
	static std::vector<std::string> temp_datatypes;
	static int reading_limit;

	std::vector<Employee*> result_empl;
	std::vector<Temporary*> result_tmp; 

	std::vector<Employee> readed_empl;
	std::vector<Secretary> readed_sec;
	std::vector<Manager> readed_managers;
	std::vector<Director> readed_directors;
	std::vector<Temporary> readed_temps;
	std::vector<Tsec> readed_tsec;
	std::vector<Consultant> readed_cons;
	std::string path;


	// methods
	std::pair<std::string, std::string> split_field(const std::string& field) const;
	Employee create_employee(std::map<std::string, std::string> fields, int fields_number) const;
	Secretary create_secretary(std::map<std::string, std::string> fields, int fields_number) const;
	Manager create_manager(std::map<std::string, std::string> fields, int fields_number, std::vector<Employee*> subs) const;
	Director create_director(std::map<std::string, std::string> fields, int fields_number, std::vector<Employee*> subs) const;
	Temporary create_temp(std::map<std::string, std::string> fields, int fields_number) const;
	Tsec create_tsec(std::map<std::string, std::string> fields, int fields_number) const;
	Consultant create_cons(std::map<std::string, std::string> fields, int fields_number) const;
	std::map<std::string, int> readed_types_counter;

	Date get_date_by_string(const std::string& date_str) const;
	void process_info_from_file();

public:
	TextReader(const std::string& path);
	std::vector<Employee*> get_employees() const;
	std::vector<Temporary*> get_temporaries() const;
};

