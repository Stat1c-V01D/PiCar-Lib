#include "Servo.h"
#include "sys.h"
#include<wiringPi.h>
#include<time.h>
#include<math.h>
#include<string>
#include<stdio.h>
#include<iostream>
#include<string>
#include<limits.h>

using namespace std;
//TODO: DEBUG messages
//TODO: bus_number is Python artifact and not needed anymore --- Removal pending

Servo::Servo(int channel, int offset, bool lock, int bus_number, int address)
{
	Servo_init(channel, offset, lock, bus_number, address);
}
//TODO: Maybe some thweaking inbetween those functions
void Servo::Servo_init(int channel, int offset, bool lock, int bus_number, int address)
{
	if (channel < 0 || channel > 16)
	{
		//TODO: Error and Limit handling
	}
	_CHANNEL = channel;
	_LOCK = lock;
	_OFFSET = offset;
	pwm = PWM(bus_number, address);
	_FREQUENCY = pwm.rt_frequency();
	write(90);
}

void Servo::setup() //TODO: Somewhat of an artifact -- Removal pending
{
	//pwm->setup();
}

int Servo::_angle_to_analog(int angle)
{
	pulse_width = pwm.map(angle, 0, 180, _MIN_PULSE_WIDTH, _MAX_PULSE_WIDTH);
	analog_value = pulse_width / 1000000;
	analog_value = analog_value * _FREQUENCY * 4096;
	int cast_anlg_val = analog_value;
	//analog_value = int(pulse_width) / 1000000 * _FREQUENCY * 4096;
	return cast_anlg_val;
}

int Servo::rt_frequency()
{
	return _FREQUENCY;
}

void Servo::frequency(int value)
{
	_FREQUENCY = value;
	pwm.frequency(value);
}

int Servo::rt_offset()
{
	return _OFFSET;
}

void Servo::offset(int value)
{
	_OFFSET = value;
}

void Servo::write(int angle)
{
	if (_LOCK)
	{
		if (angle > 180) angle = 180;
		if (angle < 0) angle = 0;
	}
	else
	{
		if (angle < 0 || angle > 180)
		{
			//TODO: Error and Limit handling
		}
	}
	int tmp_val = _angle_to_analog(angle);
	tmp_val += _OFFSET;
	pwm.write(_CHANNEL, 0, tmp_val);
}

Servo::~Servo()
{

}

void test()
{
	Servo servo = Servo(0);
	//servo->setup(); //TODO: Somewhat of an artifact -- Removal pending
	for (int i = 0; i <= 180; i += 5)
	{
		cout << i << endl;
		servo.write(i);
		delay(200);
	}
	for (int i = 180; i <= 0; i -= 5)
	{
		cout << i << endl;
		servo.write(i);
		delay(200);
	}
	for (int i = 0; i <= 90; i += 2)
	{
		cout << i << endl;
		servo.write(i);
		delay(200);
	}
}


void install()
{
	Servo  all_servo[16];
	for (int i = 0; i < 16; i++)
	{
		all_servo[i] = Servo(i);
		all_servo[i].write(0);
		delay(500);
		all_servo[i].write(180);
		delay(500);
		all_servo[i].write(90);
		delay(500);
	}
}