#pragma once
#include<string>

using namespace std;

class filedb
{
public:
	filedb(string db="NONE");
	string get(string name, string def_value = "NONE");
	void set(string name, string value);
	virtual ~filedb();

	string _DB;
};

