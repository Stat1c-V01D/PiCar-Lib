#include "filedb.h"
#include<fstream>
#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm>

//TODO: Major fixups allhtrough code -- Nothing finished or working yet

using namespace std;

filedb::filedb(string db = "NONE")
{
	if (db != "NONE")
	{
		_DB = db;
	}
	else
	{
		_DB = "config";
	}
}

string filedb::get(string name, string def_value)
{
	string tmp,value,line;
	bool flag;
	try
	{
		ifstream infile;
		infile.seekg(0, infile.end);
		long size = infile.tellg();
		infile.seekg(0);
		char* buffer = new char[size];
		infile.read(buffer, size);
		
		flag = false;
		ifstream conf;
		conf.open(name);
		while (!conf.eof())
		{
			getline(conf,line);
			if (line.find("#")!=string::npos)
			{
				if (line.find(name)!=string::npos)
				{
					tmp = line;
					value = tmp.replace(line.find(name), sizeof(name) + 1, "");
					flag = true;
				}
			}
		}
		if (flag)
		{
			return value;
		}
		else
		{
			return def_value;
		}
		conf.close();
	}
	catch (const std::exception&e)
	{
		cout << &e << endl;
	}
}

void filedb::set(string name, string value)
{
	string line, tmp, new_line,empty = ""; 
	vector<string> data;
	vector<string>::iterator it;
	bool flag;
	try
	{
		fstream conf;
		conf.open(name);
		while (!conf.eof())
		{
			getline(conf, line);
			data.push_back(line);
		}
		it = find(data.begin(), data.end(), name);
		if (it != data.end())
		{
			data.erase(it);
			data.insert(it, name + "=" + value);
		}
		else
		{
			new_line = name + "=" + value;
			data.push_back(new_line);
		}
		conf.clear();
		for (it = data.begin(); it <= data.end(); it++)
		{
			conf << line;
		}
	}
	catch (const std::exception&e)
	{
		cout << &e << endl;
	}
}


filedb::~filedb()
{
}
