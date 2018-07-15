
#include "utilities.h"
#include<string>
#include<stdio.h>
#include<iostream>

using namespace std;

int main(void)
{
	string s_in="true",s_out;
	double i_in=2.458;
	bool b_out=false, b_in = false;
	b_out = fromString<bool>(s_in);
	s_out = toString<double>(i_in);
	cout << s_in << endl << i_in << endl;
	cout << boolalpha << b_in << endl;
	cout << boolalpha << b_out << endl;
	cout << s_out << endl;
	s_out = toString<bool>(b_in);
	cout << s_out << endl;
}