#include "front_wheels.h"
#include<stdio.h>
#include<iostream>
#include<string>
#include "Servo.h"
#include "filedb.h"
#include"utilities.h"

using namespace std;

front_wheels::front_wheels(int channel, string db)
{
	init(channel, db);
}

void front_wheels::init(int channel, string db)
{
	config = filedb(db);
	_CHANNEL = channel;
	_STRAIGHT_ANGLE = 90;
	_TURNING_MAX = 20;
	_TURNING_OFFSET = fromString<int>(config.get("turning_offset", "0"));
	wheel = Servo(_CHANNEL, _TURNING_OFFSET);
	turning_max(_TURNING_MAX);
}

void front_wheels::turn_left()
{
	wheel.write(left.angle);
}

void front_wheels::turn_straight()
{
	wheel.write(straight.angle);
}

void front_wheels::turn_right()
{
	wheel.write(right.angle);
}

void front_wheels::turn(int angle)
{
	if (angle < left.angle)
	{
		angle = left.angle;
	}
	if (angle > right.angle)
	{
		angle = right.angle;
	}
	wheel.write(angle);
}

int front_wheels::rt_channel()
{
	return _CHANNEL;
}

void front_wheels::channel(int chn)
{
	_CHANNEL = chn;
}

int front_wheels::rt_turning_max()
{
	return _TURNING_MAX;
}

void front_wheels::turning_max(int angle)
{
	_TURNING_MAX = angle;
	_MIN_ANGLE = _STRAIGHT_ANGLE - angle;
	_MAX_ANGLE = _STRAIGHT_ANGLE + angle;
	left.angle = _MIN_ANGLE;
	straight.angle = _STRAIGHT_ANGLE;
	right.angle = _MAX_ANGLE;
}

int front_wheels::rt_turning_offset()
{
	return _TURNING_OFFSET;
}

void front_wheels::turning_offset(int value)
{
	_TURNING_OFFSET = value;
	config.set("turning_offset", toString<int>(value));
	wheel.offset(value);
	turn_straight();
}

void front_wheels::ready()
{
	wheel.offset(_TURNING_OFFSET);
	turn_straight();
}

void front_wheels::calibration()
{
	turn_straight();
	_CALI_TURNING_OFFSET = _TURNING_OFFSET;
}

void front_wheels::cali_left()
{
	_CALI_TURNING_OFFSET -= 1;
	wheel.offset(_CALI_TURNING_OFFSET);
	turn_straight();
}

void front_wheels::cali_right()
{
	_CALI_TURNING_OFFSET += 1;
	wheel.offset(_CALI_TURNING_OFFSET);
	turn_straight();
}

void front_wheels::cali_ok()
{
	_TURNING_OFFSET = _CALI_TURNING_OFFSET;
	config.set("turning_offset", toString<int>(_TURNING_OFFSET));
}

front_wheels::~front_wheels()
{
}