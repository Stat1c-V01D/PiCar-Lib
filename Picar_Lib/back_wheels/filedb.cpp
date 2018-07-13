#include "filedb.h"
#include<fstream>
#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm>

//TODO: Finish template return/conversion of Input/Output data
//TODO: Whole fstream operation might need to be dynamic instead of static to improve overhead <<---- Re-thinking needs to be done
using namespace std;

filedb::filedb(string db)
{
	if (db != "DEFAULT")
	{
		_DB = db;
	}
	else
	{
		_DB = "config";
	}
	fstream conf;
	conf.open(_DB, fstream::in | fstream::out);
	if (!conf)
	{
		conf.open(_DB, fstream::in | fstream::out | fstream::trunc);
		conf << "#config";
		conf.close();
	}
}

string filedb::get(string name, string def_value)
{
	string line, tmp, value;
	vector<string> data;
	vector<string>::iterator it;
	bool flag;
	fstream conf;
	try
	{
		flag = false;
		conf.open(_DB, fstream::in | fstream::out);
		while (!conf.eof())
		{
			getline(conf, line);
			data.push_back(line);
			if (line.find("#") != string::npos)
			{
				data.pop_back();
			}
		}
		it = find_if(data.begin(), data.end(), [name](const string& str) { return str.find(name) != string::npos; });
		if (it != data.end())
		{
			int index = distance(data.begin(), it);
			tmp = data.at(index);
			tmp.erase(0, tmp.find("=")+1);
			value = tmp;
			flag = true;
		}
		data.clear();
		conf.close();
	}
	catch (const std::exception&e)
	{
		//cout << &e << endl;
	}
	if (flag) return value;
	else return def_value;
}

void filedb::set(string name, string value)
{
	string line, tmp, new_line; 
	vector<string> data;
	vector<string>::iterator it;
	fstream conf;
	try
	{
		conf.open(_DB, fstream::in | fstream::out);
		while (!conf.eof())
		{
			getline(conf, line);
			data.push_back(line);
		}
		conf.close();
		it = find_if(data.begin(), data.end(), [name](const string& str) { return str.find(name) != string::npos; });
		if (it != data.end())
		{
			data.erase(it);
			data.insert(it, name + "=" + value);
		}
		else
		{
			new_line = name + "=" + value ;
			data.push_back(new_line);
		}
		for (size_t i = 0; i <= data.size(); i++)
		{
			it = find(data.begin(), data.end(), "");
			if (it != data.end())
			{
				data.erase(it);
			}
		}
		conf.open(_DB, fstream::in | fstream::out | fstream::trunc);
		for (size_t o_it = 0; o_it <= data.size(); o_it++)
		{
			conf << data.at(o_it) << endl;
		}
		data.clear();
		conf.close();
	}
	catch (const std::exception&e)
	{
		//cout << &e << endl;
	}
}

void filedb::remove(string name)
{
}


filedb::~filedb()
{
}
