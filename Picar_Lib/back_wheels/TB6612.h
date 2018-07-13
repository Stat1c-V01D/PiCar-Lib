#pragma once
class TB6612
{
public:
	TB6612(int direction_channel = -1, int pwm = -1, bool offset = true);
	void TB6612_init(int direction_channel, int pwm, bool offset);
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
		_SPWM,
		_SPEED,
		_PWM;

	bool _OFFSET,
		_FORWARD_OFFSET,
		_BACKWARD_OFFSET;
};

void test();
