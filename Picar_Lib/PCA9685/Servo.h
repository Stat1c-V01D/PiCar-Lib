#pragma once
#include "PWM.h"
#include<string.h>

using namespace std;


class Servo : public PWM
{
public:
	Servo();
	virtual ~Servo();
	
	int _MIN_PULSE_WIDTH = 600,
		_MAX_PULSE_WIDTH = 2400,
		_DEFAULT_PULSE_WIDTH = 1500,
		_SFREQUENCY = 60;

	bool _DEBUG = false;
	string	_DEBUG_INFO = "DEBUG 'Servo.py':";
};

