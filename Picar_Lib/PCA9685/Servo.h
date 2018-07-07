#pragma once
#include "PWM.h"
#include<string.h>
#include<limits.h>

//TODO: DEBUG messages
//TODO: bus_number is Python artifact and not needed anymore --- Removal pending

using namespace std;


class Servo : public PWM
{
public:
	Servo(int channel = -1, int offset = 0, bool lock = true, int bus_number = -1, int address = 0x40);
	void Servo_init(int channel, int offset, bool lock, int bus_number, int address);
	void setup();
	int _angle_to_analog(int angle);
	int rt_frequency();
	void frequency(int value);
	int rt_offset();
	void offset(int value);
	void write(int angle);
	virtual ~Servo();
	PWM pwm;
	int _MIN_PULSE_WIDTH = 600,
		_MAX_PULSE_WIDTH = 2400,
		_DEFAULT_PULSE_WIDTH = 1500,
		_SFREQUENCY = 60,
		_CHANNEL,
		_OFFSET,
		_FREQUENCY;
		

	double pulse_width;
	double analog_value;

	bool _DEBUG = false,
		 _LOCK;
	string	_DEBUG_INFO = "DEBUG 'Servo.py':";
};

void test();
void install();