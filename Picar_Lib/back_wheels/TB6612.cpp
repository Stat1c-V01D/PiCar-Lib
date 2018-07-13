#include "TB6612.h"
#include "PWM.h"
#include<wiringPi.h>
#include<stdlib.h>
#include<stdio.h>

//TODO: Fix limited compatibility with PWM class not working
//TODO:Check all classes and subclasses for function on Rpi

TB6612::TB6612(int direction_channel, int pwm, bool offset)
{
	TB6612_init(direction_channel, pwm, offset);
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
	if (speed != -1)
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

void TB6612::pwm(int speed)
{
	PWM pwm = PWM();
	double pulse_width = pwm.map(speed, 0, 100, 0, 4095);
	_PWM = int(pulse_width);
	pwm.write(_SPWM, 0, _PWM);
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