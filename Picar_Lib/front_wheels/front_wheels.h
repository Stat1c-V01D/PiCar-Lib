#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include"Servo.h"
#include"filedb.h"
using namespace std;

class front_wheels :public Servo
{
public:
	front_wheels(int channel = -1, string db = "config");
	void init(int channel,string db);
	void turn_left();
	void turn_straight();
	void turn_right();
	void turn(int angle);
	int rt_channel();
	void channel(int chn);
	int rt_turning_max();
	void turning_max(int angle);
	int rt_turning_offset();
	void turning_offset(int value);
	void ready();
	void calibration();
	void cali_left();
	void cali_right();
	void cali_ok();
	virtual ~front_wheels();

	Servo wheel;
	filedb config;

	int _CHANNEL,
		_STRAIGHT_ANGLE,
		_TURNING_MAX,
		_TURNING_OFFSET,
		_CALI_TURNING_OFFSET,
		_MIN_ANGLE,
		_MAX_ANGLE;

	struct _ANGLE
	{
		int angle;
	};
	_ANGLE left;
	_ANGLE straight;
	_ANGLE right;
};

