#pragma once
#include<string>
#include<cstdio>
using namespace std;

class PWM
{
public:
	PWM();
	int _get_bus();
	string _get_pi_ver();
	void setup();
	virtual ~PWM();

	int _MODE1 = 0x00,
		_MODE2 = 0x01,
		_SUBADR1 = 0x02,
		_SUBADR2 = 0x03,
		_SUBADR3 = 0x04,
		_PRESCALE = 0xFE,
		_LED0_ON_L = 0x06,
		_LED0_ON_H = 0x07,
		_LED0_OFF_L = 0x08,
		_LED0_OFF_H = 0x09,
		_ALL_LED_ON_L = 0xFA,
		_ALL_LED_ON_H = 0xFB,
		_ALL_LED_OFF_L = 0xFC,
		_ALL_LED_OFF_H = 0xFD,
		_RESTART = 0x80,
		_SLEEP = 0x10,
		_ALLCALL = 0x01,
		_INVRT = 0x10,
		_OUTDRV = 0x04;


	string RPI_REVISION_0[1] = { "900092" };
	string RPI_REVISION_1_MODULE_B[9] = { "Beta", "0002", "0003", "0004", "0005", "0006", "000d", "000e", "000f" };
	string RPI_REVISION_1_MODULE_A[3] = { "0007", "0008", "0009" };
	string RPI_REVISION_1_MODULE_BP{ "0010, 0013" };
	string RPI_REVISION_1_MODULE_AP{ "0012" };
	string RPI_REVISION_2{ "a01041, a21041" };
	string RPI_REVISION_3{ "a02082, a22082" };  //TODO: Find suitable string array for compare and find

	string _DEBUG_INFO = "DEBUG 'PCA9685.py':";

	bool _DEBUG = false;

};

