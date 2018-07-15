#include "TB6612.h"
#include<wiringPi.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include "PWM.h"
#include "utilities.h"

TB6612::TB6612(int direction_channel, int pwm_channel, bool offset)
{
	TB6612_init(direction_channel, pwm_channel, offset);
}

void TB6612::TB6612_init(int direction_channel, int pwm_channel, bool offset)
{
	_DIRECTION_CHANNEL = direction_channel;
	_CPWM = pwm_channel;
	_OFFSET = offset;
	_FORWARD_OFFSET = offset;
	_BACKWARD_OFFSET = !offset;
	_SPEED = 0;
	_PULSE = 0;
	wiringPiSetupGpio();
	pinMode(direction_channel, OUTPUT);
}

int TB6612::rt_speed()
{
	return _SPEED;
}

void TB6612::speed(int speed)
{
	if (speed!=-1)
	{
		if (speed > 100) speed = 100;
		if (speed < 0) speed = 0;
		_SPEED = speed;
		pwm(speed);
	}
	else
	{
		//TODO: Scrub Nub Error handling!
	}
}

void TB6612::forward()
{
	digitalWrite(_DIRECTION_CHANNEL, !btoInt(_FORWARD_OFFSET));
}

void TB6612::backward()
{
	digitalWrite(_DIRECTION_CHANNEL, !btoInt(_BACKWARD_OFFSET));
}

void TB6612::stop()
{
	_SPEED = 0;
	pwm(_SPEED);
}

bool TB6612::rt_offset()
{
	return _OFFSET;
}

void TB6612::offset(bool value)
{
	if (value == true || value == false)
	{
		_FORWARD_OFFSET = value;
		_BACKWARD_OFFSET = !value;
	}
	else
	{
		//TODO: Scrub Nub Error handling!
	}
}

int TB6612::rt_pwm()
{
	return _PWM;
}

void TB6612::pwm(int speed)
{
	_PULSE = drive_pwm.map(speed, 0, 100, 0, 4095);
	_PWM = _PULSE;
	drive_pwm.write(_CPWM, 0, _PULSE);
	//int speed_map = pwm * 1023 / 100; //Mapping 0 to 100 speed over 0 to 1023 pwm value
	//_PWM = speed_map;
}


TB6612::~TB6612()
{
}

/*
void test() //Deprecated Code -- Artifact
{
TB6612 motorA = TB6612(23);
TB6612 motorB = TB6612(24);
int a_pwm = 27,
b_pwm = 22;
pinMode(a_pwm, OUTPUT);
pinMode(b_pwm, OUTPUT);
motorA.forward();
for (int i = 1; i < 101; i++)
{
motorA.speed(i);
pwmWrite(a_pwm, (motorA.rt_pwm() * 1023 / 100));
}
motorA.backward();
for (int i = 1; i < 101; i++)
{
motorA.speed(i);
pwmWrite(a_pwm, (motorA.rt_pwm() * 1023 / 100));
}
motorB.forward();
for (int i = 1; i < 101; i++)
{
motorB.speed(i);
pwmWrite(b_pwm, (motorB.rt_pwm() * 1023 / 100));
}
motorB.backward();
for (int i = 1; i < 101; i++)
{
motorB.speed(i);
pwmWrite(b_pwm, (motorB.rt_pwm() * 1023 / 100));
}
}
*/


int btoInt(bool in)
{
	if (in == true)
	{
		return 1;
	}
	else
	{
		return 0;
	}
};