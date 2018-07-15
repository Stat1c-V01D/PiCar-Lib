#include <wiringPi.h>
#include "back_wheels.h"


int main(void)
{
	back_wheels bw = back_wheels();
	bw.forward();
	for (size_t i = 0; i < 101; i++)
	{
		bw.speed(i);
		delay(10);
	}
	delay(500);
	for (size_t i = 101; i > 0; i--)
	{
		bw.speed(i);
		delay(10);
	}
	delay(1000);
	bw.backward();
	for (size_t i = 0; i < 101; i++)
	{
		bw.speed(i);
		delay(10);
	}
	delay(500);
	for (size_t i = 101; i > 0; i--)
	{
		bw.speed(i);
		delay(10);
	}
	delay(1000);
	bw.stop();
}