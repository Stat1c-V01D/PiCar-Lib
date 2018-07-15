#pragma once
#include<string>
#include<fstream>
#include<stdio.h>
#include<iostream>
using namespace std;

class filedb
{
public:
	filedb(string db="DEFAULT");
	string get(string name, string def_value = "DEFAULT");
	void set(string name, string value);
	void remove(string name); //TODO: only Code Skeletton at the moment -- Not yet implemented
	void clear(string db); //TODO: only Code Skeletton at the moment -- Not yet implemented
	virtual ~filedb();
	string _DB;
};

