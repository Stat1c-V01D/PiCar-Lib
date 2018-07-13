#pragma once
#include<string>
#include<cstdio>
using namespace std;

//TODO: DEBUG messages
//TODO: bus_number is Python artifact and not needed anymore --- Removal pending

class PWM
{
public:
	PWM(int bus_number = -1, int address = 0x40);
	void PWM_init(int bus_number , int address);
	void setup();
	void _write_byte_data(int reg, int value);
	int _read_byte_data(int reg);
	void _check_i2c();
	int rt_frequency();
	void frequency(int freq);
	void write(int channel, int on, int off);
	void write_all_value(int on, int off);
	double map(int x, int in_min, int in_max, int out_min, int out_max);

	/* Deprecated Python Code for SMBus compatibility
	int _get_bus();
	string _get_pi_ver();
	*/

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

	/* Deprecated Python Code for SMBus compatibility
	string RPI_REVISION[20] = { "900092", //RPI_REVISION_0
								"Beta", "0002", "0003", "0004", "0005", "0006", "000d", "000e", "000f", //RPI_REVISION_1_MODULE_B
								"0007", "0008", "0009", //RPI_REVISION_1_MODULE_A
								"0010, 0013", //RPI_REVISION_1_MODULE_BP
								"0012",  //RPI_REVISION_1_MODULE_AP
								"a01041", "a21041", //RPI_REVISION_2
								"a02082", "a22082" }; //RPI_REVISION_3
	*/

	string _DEBUG_INFO = "DEBUG 'PCA9685.py':";

	bool _DEBUG = false;


private:
	int _ADDRESS = 0x00,
		_BUS = 0,
		_FREQUENCY = 0,
		_DEVICE;

protected:
};

