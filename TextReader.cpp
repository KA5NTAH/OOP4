#include "TextReader.h"

using namespace std;
using DataContainer = pair<string, map<string, string>>;

vector <string> TextReader::empl_datatypes = { "Employee", "Secretary", "Manager", "Director"};
vector <string> TextReader::temp_datatypes = { "Temporary", "Tsec", "Consultant" };
int TextReader::reading_limit = 100;

pair<string, string> TextReader::split_field(const string& field) const {		
	// split field into name and value
	int delimiter_pos = field.find(field_delimiter);
	string field_name = field.substr(0, delimiter_pos);
	string field_value = field.substr(delimiter_pos + 1, field.size() - delimiter_pos);
	pair<string, string> res (field_name, field_value);
	return res;
}


Date TextReader::get_date_by_string(const string& date_str) const {
	int y = stoi(date_str.substr(date_str.size() - 4, 4));
	int d = stoi(date_str.substr(0, 2));
	int m = stoi(date_str.substr(3, 2));
	return Date(y, m, d);
}


Employee TextReader::create_employee(map<string, string> fields, int fields_number) const {
	Employee result;
	if (fields_number > 0) {
		string fname = fields["first_name"];
		int department = stoi(fields["department"]);
		if (fields_number == 2) {
			// first case name and department
			result = Employee(fname, department);
		}
		else {
			// all fields
			string fam_name = fields["family_name"];
			char mid_name = fields["middle_name_init_letter"][0];
			Date hir_date = this->get_date_by_string(fields["hiring_date"]);
			result = Employee(fname, mid_name, fam_name, hir_date, department);
		}
	}
	return result;
}


Secretary TextReader::create_secretary(map<string, string> fields, int fields_number) const {
	Secretary result;
	//Secretary();
	//Secretary(const std::string & fname, const short int& department);
	//Secretary(const std::string & fnam, const char& mid_name, const std::string & fam_nam, const Date & hir_date, const short int& dep, const bool& eng_knowledge);
	if (fields_number != 0) {
		string fname = fields["first_name"];
		int department = stoi(fields["department"]);
		if (fields_number == 2) {
			result = Secretary(fname, department);
		}
		else {
			string fam_name = fields["family_name"];
			char mid_name = fields["middle_name_init_letter"][0];
			Date hir_date = this->get_date_by_string(fields["hiring_date"]);
			bool eng_knowledge = fields["eng_knowledge"] == "yes";
			result = Secretary(fname, mid_name, fam_name, hir_date, department, eng_knowledge);
		}
	}
	return result;
}


Manager TextReader::create_manager(map<string, string> fields, int fields_number, vector <Employee*> subs) const {
	//Manager();
	//Manager(const std::string & fname, const short int& dep, const short int& lvl);
	//Manager(const std::string & fnam, const char& mid_name, const std::string & fam_nam,
		//const Date & hir_date, const short int& dep, const std::set<Employee*> & group, const short int& lvl);
	Manager result;
	if (fields_number != 0) {
		string fname = fields["first_name"];
		int department = stoi(fields["department"]);
		int lvl = stoi(fields["level"]);
		if (fields_number == 3) {
			result = Manager(fname, department, lvl);
		}
		else {
			string fam_name = fields["family_name"];
			char mid_name = fields["middle_name_init_letter"][0];
			Date hir_date = this->get_date_by_string(fields["hiring_date"]);
			set <Employee*> group;
			for (auto slave : subs) group.insert(slave);
			result = Manager(fname, mid_name, fam_name, hir_date, department, group, lvl);
		}
	}
	return result;
}


Director TextReader::create_director(map<string, string> fields, int fields_number, vector <Employee*> subs) const {
	//Director();
	//Director(const std::string & fnam, const short int& dep, const short int& lvl);
	//Director(const std::string & fnam, const char& mid_name, const std::string & fam_nam,
		//const Date & hir_date, const short int& dep, const std::set<Employee*> & group,
		//const short int& lvl, const short int& years_of_service);
	Director result;
	if (fields_number != 0) {
		string fname = fields["first_name"];
		int department = stoi(fields["department"]);
		int lvl = stoi(fields["level"]);
		if (fields_number == 3) {
			result = Director(fname, department, lvl);
		}
		else {
			string fam_name = fields["family_name"];
			char mid_name = fields["middle_name_init_letter"][0];
			Date hir_date = this->get_date_by_string(fields["hiring_date"]);
			set <Employee*> group;
			for (auto slave : subs) group.insert(slave);
			int service_years = stoi(fields["years_of_service"]);
			result = Director(fname, mid_name, fam_name, hir_date, department, group, lvl, service_years);
		}
	}
	return result;
}


Temporary TextReader::create_temp(map<string, string> fields, int fields_number) const {
	//std::string first_name, family_name;
	//Temporary(const std::string & fnam, const std::string & fam_nam, const Date & beg, const Date & end);
	//Temporary(const Date & beg, const Date & end);
	if (fields_number == 0) 
	{
		Temporary result;
		return result;
	}
	Date beg = this->get_date_by_string(fields["begin"]);
	Date end = this->get_date_by_string(fields["end"]);
	if (fields_number == 2) {
		return Temporary(beg, end);
	}
	else {
		string fname = fields["first_name"];
		string fam_name = fields["family_name"];
		return Temporary(fname, fam_name, beg, end);
	}
}


Tsec TextReader::create_tsec(map<string, string> fields, int fields_number) const {
	//Tsec(const std::string & fnam, const char& mid_name, const std::string & fam_nam, const Date & hir_date, const short int& dep, const bool& eng_knowledge,
		//const Date & beg, const Date & end);
	if (fields_number == 0)
	{
		Tsec result;
		return result;
	}
	string fname = fields["first_name"];
	int department = stoi(fields["department"]);
	string fam_name = fields["family_name"];
	char mid_name = fields["middle_name_init_letter"][0];
	Date hir_date = this->get_date_by_string(fields["hiring_date"]);
	bool eng_knowledge = fields["eng_knowledge"] == "yes";
	Date beg = this->get_date_by_string(fields["begin"]);
	Date end = this->get_date_by_string(fields["end"]);
	return Tsec(fname, mid_name, fam_name, hir_date, department, eng_knowledge, end);
}


Consultant TextReader::create_cons(map<string, string> fields, int fields_number) const {
	//int consul_rating
	//Consultant(const std::string & fname, const std::string & fam_nam, const Date & beg, const Date & end, const int& rate)
	if (fields_number == 0)
	{
		Consultant result;
		return result;
	}
	string fname = fields["first_name"];
	string fam_name = fields["family_name"];
	Date beg = this->get_date_by_string(fields["begin"]);
	Date end = this->get_date_by_string(fields["end"]);
	int rate = stoi(fields["consul_rating"]);
	return Consultant(fname, fam_name, beg, end, rate);
}


TextReader::TextReader(const string& path) {
	for (auto t : TextReader::empl_datatypes) this->readed_types_counter[t] = 0;
	for (auto t : TextReader::temp_datatypes) this->readed_types_counter[t] = 0;
	this->path = path;
	this->result_empl = {};
	this->result_tmp = {};
	this->readed_empl = vector<Employee>(TextReader::reading_limit);
	this->readed_cons = vector<Consultant>(TextReader::reading_limit);
	this->readed_directors = vector<Director>(TextReader::reading_limit);
	this->readed_managers = vector<Manager>(TextReader::reading_limit);
	this->readed_sec = vector<Secretary>(TextReader::reading_limit);
	this->readed_temps= vector<Temporary>(TextReader::reading_limit);
	this->readed_tsec = vector<Tsec>(TextReader::reading_limit);
	this->process_info_from_file();
}


void TextReader::process_info_from_file() {
	// todo analyse every string in the file 
	string line;
	ifstream myfile(this->path);
	if (myfile.is_open())
	{
		stack<DataContainer> workers; // stack in order to process nested datatypes
		stack <vector<Employee*>> subordinates; // todo more suitable name
		bool curr_worker_is_tmp = false;
		while (getline(myfile, line)) // outer loop process line in file 
		{			
			// preprocess the line 
			// delete leading whitespaces
			int start_pos = line.find_first_not_of(" \t");
			line = line.substr(start_pos, line.size() - start_pos);
			// delete trailing whitespaces
			int finish_pos = line.find_last_not_of(" \t");
			line = line.substr(0, finish_pos + 1);
			bool empl_dtype = find(TextReader::empl_datatypes.begin(), TextReader::empl_datatypes.end(), line) != TextReader::empl_datatypes.end();
			bool tmp_dtype = find(TextReader::temp_datatypes.begin(), TextReader::temp_datatypes.end(), line) != TextReader::temp_datatypes.end();
			
			// begin stage : initialize container for new class
			if (empl_dtype or tmp_dtype) 
			{											
				curr_worker_is_tmp = tmp_dtype;
				DataContainer newby;
				newby.first = line;
				workers.push(newby);
				vector<Employee*> newby_subs;
				subordinates.push(newby_subs);							
			}

			// end stage : create class with obtained data
			else if (line == text_info_end)
			{	
				// this employee is done pull all information about him
				DataContainer worker = workers.top();
				workers.pop();
				vector <Employee*> w_subord = subordinates.top();
				subordinates.pop();			
				string worker_type = worker.first;
				map<string, string> fields = worker.second;
				int fields_number = fields.size();
				// use data to create class  
				if (curr_worker_is_tmp) {
					// temporary class cannot have any subordinates					
					if (worker_type == "Temporary") {
						Temporary value = this->create_temp(fields, fields_number);
						int ind = this->readed_types_counter[worker_type];
						this->readed_temps[ind] = value;						
						this->result_tmp.push_back(&this->readed_temps[ind]);
					}
					else if (worker_type == "Tsec") {
						Tsec value = this->create_tsec(fields, fields_number);
						int ind = this->readed_types_counter[worker_type];
						this->readed_tsec[ind] = value;
						this->result_tmp.push_back(&this->readed_tsec[ind]);
					}
					else if (worker_type == "Consultant") {
						Consultant value = this->create_cons(fields, fields_number);
						int ind = this->readed_types_counter[worker_type];
						this->readed_cons[ind] = value;
						this->result_tmp.push_back(&this->readed_cons[ind]);
					}
				}
				else {
					// create class wrt type 					
					if (worker_type == "Employee") {
						Employee value = this->create_employee(fields, fields_number);						
						int ind = this->readed_types_counter[worker_type];
						this->readed_empl[ind] = value;
						this->result_empl.push_back(&this->readed_empl[ind]);
					}
					else if (worker_type == "Secretary") {
						Secretary value = this->create_secretary(fields, fields_number);
						int ind = this->readed_types_counter[worker_type];
						this->readed_sec[ind] = value;
						this->result_empl.push_back(&this->readed_sec[ind]);
					}
					else if (worker_type == "Manager") {
						Manager value = this->create_manager(fields, fields_number, w_subord);
						int ind = this->readed_types_counter[worker_type];
						this->readed_managers[ind] = value;
						this->result_empl.push_back(&this->readed_managers[ind]);
					}
					else if (worker_type == "Director") {
						Director value = this->create_director(fields, fields_number, w_subord);
						int ind = this->readed_types_counter[worker_type];
						this->readed_directors[ind] = value;
						this->result_empl.push_back(&this->readed_directors[ind]);
					}

					// decide what is to be done with the class instance
					if (not workers.empty()) {						
						// if stack is not empty this employee is a slave that the other
						vector <Employee*> boss_subordinates = subordinates.top();
						subordinates.pop();						
						boss_subordinates.push_back(this->result_empl.back());
						subordinates.push(boss_subordinates);
					}
				}				
				// update index
				this->readed_types_counter[worker_type]++;
			}

			// mid stage : fields processing
			else
			{								
				DataContainer curr_worker = workers.top();
				// delete old version
				workers.pop();		

				// create new version + push
				pair<string, string> splitted_field = split_field(line);				
				curr_worker.second.insert(splitted_field);
				workers.push(curr_worker);
			}
		}
		myfile.close();
	}
}


vector<Employee*> TextReader::get_employees() const {
	return this->result_empl;
}


vector<Temporary*> TextReader::get_temporaries() const {
	return this->result_tmp;
}