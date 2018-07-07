#include <wiringPi.h>
#include "PWM.h"
#include "Servo.h"
#include<stdio.h>
#include<iostream>

int main(void)
{
	/*
	try
	{
		PWM * pwm = new PWM();
		pwm->frequency(60);
		for (int i = 0; i < 16; i++)
		{
			cout << "CH: " << i << endl;
			delay(5);
			for (int j = 0; j <= 4096; j++)
			{
				pwm->write(i, 0, j);
				//cout << "PWM: " << j << endl;
				delayMicroseconds(30);
			}
		}
	}
	catch (const std::exception&e)
	{
		cout << &e << endl;
	}
	*/
	try
	{
		install();
	}
	catch (const std::exception&e)
	{
		cout << &e << endl;
	}
}