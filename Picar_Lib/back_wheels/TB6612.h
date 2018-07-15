#pragma once
#include "PWM.h"

class TB6612 :public PWM
{
public:
	TB6612(int direction_channel = -1, int pwm_channel = -1, bool offset = true);
	void TB6612_init(int direction_channel, int pwm_channel, bool offset);
	int rt_speed();
	void speed(int speed);
	void forward();
	void backward();
	void stop();
	bool rt_offset();
	void offset(bool value);
	int rt_pwm();
	void pwm(int speed);
	virtual ~TB6612();

	int _DIRECTION_CHANNEL,
		_CPWM,
		_SPEED,
		_PWM,
		_PULSE;

	bool _OFFSET,
		_FORWARD_OFFSET,
		_BACKWARD_OFFSET;

	PWM drive_pwm = PWM();
};

//void test();
int btoInt(bool in);