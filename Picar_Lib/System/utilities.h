#pragma once
#include<string>
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<typeinfo>

using namespace std;

template <class T>
T fromString(const string& s) {
	if (typeid(T) == typeid(bool))
	{
		if (s == "true") return true;
		else if (s == "false") return false;
		else return false;
	}
	else
	{
		stringstream ss(s);
		T t;
		ss >> t;
		return t;
	}
}

template <class T>
string toString(T in) {
	if (typeid(T) == typeid(bool))
	{
		if (in == true) return "true";
		else if (in == false) return "false";
		else return "Error";
	}
	else
	{
		stringstream ss;
		ss << in;
		return ss.str();
	}
}
