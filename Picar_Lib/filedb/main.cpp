#include <wiringPi.h>
#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include "filedb.h"

int main(void)
{	
	filedb * conf = new filedb();
	conf->set("pwm", "255");
	conf->set("speed", "80");
	cout << conf->get("pwm") << endl;
	cout << conf->get("speed")<< endl;
	conf->set("pwm", "125");
	cout << conf->get("pwm") << endl;
	delay(5000);
}