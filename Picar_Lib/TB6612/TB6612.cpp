#include "TB6612.h"
#include<wiringPi.h>
#include<stdlib.h>
#include<stdio.h>

//TODO: Fix limited compatibility

TB6612::TB6612(int direction_channel)
{
	TB6612_init(direction_channel);
}

void TB6612::TB6612_init(int direction_channel, int pwm, bool offset)
{
	_DIRECTION_CHANNEL = direction_channel;
	_SPWM = pwm;
	_OFFSET = offset;
	_FORWARD_OFFSET = offset;
	_BACKWARD_OFFSET != offset;
	_SPEED = 0;
	system("sudo wiringPiSetupGpio()");
	pinMode(direction_channel, OUTPUT);
}

int TB6612::rt_speed()
{
	return _SPEED;
}

void TB6612::speed(int speed)
{
	if (speed != 'NONE')
	{
		if (speed > 100) speed = 100;
		if (speed < 0) speed = 0;
	}
	else
	{
		//TODO: Scrub Nub Error handling!
	}
	_SPEED = speed;
	pwm(speed);
}

void TB6612::forward()
{
	digitalWrite(_DIRECTION_CHANNEL, _FORWARD_OFFSET);
}

void TB6612::backward()
{
	digitalWrite(_DIRECTION_CHANNEL, _BACKWARD_OFFSET);
}

void TB6612::stop()
{
	_SPEED = 0;
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
		_BACKWARD_OFFSET != value;
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

void TB6612::pwm(int pwm)
{
	_SPWM = pwm;
	_PWM = pwm;
	//int speed_map = pwm * 1023 / 100; //Mapping 0 to 100 speed over 0 to 1023 pwm value
	//_PWM = speed_map;
}


TB6612::~TB6612()
{
}


void test()
{
	int a_pwm = 27,
		b_pwm = 22;
	pinMode(a_pwm, OUTPUT);
	pinMode(b_pwm, OUTPUT);
	TB6612 motorA = TB6612(17);
	TB6612 motorB = TB6612(18);
	motorA.forward();
	for (int i = 0; i < 101; i++)
	{
		motorA.speed(i);
		pwmWrite(a_pwm, (motorA.rt_pwm() * 1023 / 100));
	}
	motorA.backward();
	for (int i = 0; i < 101; i++)
	{
		motorA.speed(i);
		pwmWrite(a_pwm, (motorA.rt_pwm() * 1023 / 100));
	}
	motorB.forward();
	for (int i = 0; i < 101; i++)
	{
		motorB.speed(i);
		pwmWrite(b_pwm, (motorB.rt_pwm() * 1023 / 100));
	}
	motorB.backward();
	for (int i = 0; i < 101; i++)
	{
		motorB.speed(i);
		pwmWrite(b_pwm, (motorB.rt_pwm() * 1023 / 100));
	}
}