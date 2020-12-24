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
#include "TextReader.h";


using namespace std;
int main()
{	
	string path = "TextData.txt";
	TextReader reader(path);
	vector<Employee*> empl_result = reader.get_employees();
	for (auto x : empl_result) x->print_info();
	vector<Temporary*> tmp_result = reader.get_temporaries();
	for (auto x : tmp_result)
	{
		x->print_tmp_info();
		cout << "\n";
	}
}