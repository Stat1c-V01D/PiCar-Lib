#include "TB6612.h"
#include<wiringPi.h>
#include<stdlib.h>

TB6612::TB6612(int direction_channel)
{
	TB6612_init(direction_channel);
}

void TB6612::TB6612_init(int direction_channel, int pwm, bool offset)
{
	_DIRECTION_CHANNEL = direction_channel;
	_PWM = pwm;
	_OFFSET = offset;
	_FORWARD_OFFSET = offset;
	_BACKWARD_OFFSET != offset;
	_SPEED = 0;
	wiringPiSetupSys();
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
	//_PWM = speed;
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
	_PWM = pwm;
}


TB6612::~TB6612()
{
}


void test()
{
	pinMode(27, OUTPUT);
	pinMode(22, OUTPUT);
	
}