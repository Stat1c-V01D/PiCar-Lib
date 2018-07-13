#pragma once
#include<string>
#include<stdio.h>
#include<iostream>
#include<sstream>

template <class T>
T fromString(const string& s) {
	stringstream ss(s);
	T t;
	ss >> t;
	return t;
}

template <class T>
string toString(T in) {
	stringstream ss;
	ss << in;
	return ss.str();
}
