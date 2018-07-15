#include "back_wheels.h"
#include "filedb.h"
#include "TB6612.h"
#include "utilities.h"


back_wheels::back_wheels(string db)
{
	init(db);
}

void back_wheels::init(string db)
{
	config = filedb(db);
	_FORWARD_A = fromString<bool>(config.get("forward_A", "true"));
	_FORWARD_B = fromString<bool>(config.get("forward_B", "true"));
	left_wheel = TB6612(_MOTOR_A, _PWM_A, _FORWARD_A);
	right_wheel = TB6612(_MOTOR_B, _PWM_B, _FORWARD_B);
	_SPEED = 0;
}

void back_wheels::forward()
{
	left_wheel.forward();
	right_wheel.forward();
}

void back_wheels::backward()
{
	left_wheel.backward();
	right_wheel.backward();
}

void back_wheels::stop()
{
	left_wheel.stop();
	right_wheel.stop();
}

int back_wheels::rt_speed()
{
	return _SPEED;
}

void back_wheels::speed(int s_speed)
{
	_SPEED = s_speed;
	left_wheel.speed(_SPEED);
	right_wheel.speed(_SPEED);
}

void back_wheels::ready()
{
	left_wheel.offset(_FORWARD_A);
	right_wheel.offset(_FORWARD_B);
	stop();
}

void back_wheels::calibration()
{
	speed(50);
	forward();
	cali_forward_A = _FORWARD_A;
	cali_forward_B = _FORWARD_B;
}

void back_wheels::cali_left()
{
	cali_forward_A = (1 + cali_forward_A) & 1;
	left_wheel.offset(cali_forward_A);
	forward();
}

void back_wheels::cali_right()
{
	cali_forward_B = (1 + cali_forward_B) & 1;
	right_wheel.offset(cali_forward_B);
	forward();
}

void back_wheels::cali_ok()
{
	_FORWARD_A = cali_forward_A;
	_FORWARD_B = cali_forward_B;
	config.set("forward_A", toString<bool>(_FORWARD_A));
	config.set("forward_B", toString<bool>(_FORWARD_B));
}


back_wheels::~back_wheels()
{
}
