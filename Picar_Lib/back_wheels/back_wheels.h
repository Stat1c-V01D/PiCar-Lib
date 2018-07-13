#pragma once
#include<string>
#include "PWM.h"
#include "filedb.h"
#include "TB6612.h"
using namespace std;
class back_wheels
{
public:
	back_wheels(string db="config");
	void init(string db);
	void forward();
	void backward();
	void stop();
	int rt_speed();
	void speed(int s_speed);
	void ready();
	void calibration();
	void cali_left();
	void cali_right();
	void cali_ok();
	virtual ~back_wheels();

	filedb config;
	TB6612 left_wheel;
	TB6612 right_wheel;
	PWM pwm;
	const int _MOTOR_A = 17,
		_MOTOR_B = 27,
		_PWM_A = 4,
		_PWM_B = 5;
	int _SPEED;
	bool _FORWARD_A = true,
		_FORWARD_B = true,
		cali_forward_A = true,
		cali_forward_B = true;
};


