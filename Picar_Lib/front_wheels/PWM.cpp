#include "PWM.h"
#include<wiringPi.h>
#include<wiringPiI2C.h>
#include<time.h>
#include<math.h>
#include<string>
#include<fstream>
#include<stdio.h>
#include<iostream>
//TODO: DEBUG messages
//TODO: bus_number is Python artifact and not needed anymore --- Removal pending
using namespace std;

PWM::PWM(int bus_number, int address)
{
	PWM_init(bus_number, address);
}

void PWM::PWM_init(int bus_number, int address)
{
	_ADDRESS = address;
	/* Deprecated Python Code for SMBus compatibility
	if (bus_number == -1)
	{
		_BUS = _get_bus();
	}
	else
	{
		_BUS = bus_number;
	}
	*/
	_DEVICE = wiringPiI2CSetup(address);
	setup();
}


/* Deprecated Python Code for SMBus compatibility
int PWM::_get_bus()
{
	string pi_revision = _get_pi_ver();
	if (pi_revision.compare("0") == 0)
	{
		return 0;
	}
	else if (pi_revision.compare("1 Module B") == 0)
	{
		return 0;
	}
	else if (pi_revision.compare("1 Module A") == 0)
	{
		return 0;
	}
	else if (pi_revision.compare("1 Module B+") == 0)
	{
		return 1;
	}
	else if (pi_revision.compare("1 Module A+") == 0)
	{
		return 0;
	}
	else if (pi_revision.compare("2 Module B") == 0)
	{
		return 1;
	}
	else if (pi_revision.compare("3 Module B") == 0)
	{
		return 1;
	}
	else
	{
		printf("Revision couldn't be determined");
	}
}

string PWM::_get_pi_ver()  //TODO: Could be Implemented in _get_bus() function directly
{
	ifstream file;
	string tmp_data;
	try
	{
		file.open("/proc/cpuinfo");
		while (!file.eof())
		{
			getline(file, tmp_data);
			if (tmp_data.find("Revision"))
			{
				if (tmp_data.find(RPI_REVISION[0])) return "0"; //RPI_REVISION_0
				for (int i = 1; i < 10; i++)
				{
					if (tmp_data.find(RPI_REVISION[i])) return "1 Module B"; //RPI_REVISION_1_MODULE_B
				}
				for (int i = 10; i < 13; i++)
				{
					if (tmp_data.find(RPI_REVISION[i])) return "1 Module A"; //RPI_REVISION_1_MODULE_A
				}
				for (int i = 13; i < 15; i++)
				{
					if (tmp_data.find(RPI_REVISION[i])) return "1 Module B+"; //RPI_REVISION_1_MODULE_BP
				}
				if (tmp_data.find(RPI_REVISION[15])) return "1 Module A+"; //RPI_REVISION_1_MODULE_AP
				for (int i = 16; i < 18; i++)
				{
					if (tmp_data.find(RPI_REVISION[i])) return "2 Module B"; //RPI_REVISION_2
				}
				for (int i = 18; i < 20; i++)
				{
					if (tmp_data.find(RPI_REVISION[i])) return "3 Module B"; //RPI_REVISION_3
				}
			}

		}
	}
	catch (const std::exception&e)
	{
		file.close();
		cout << &e << endl;
		cout << "Exiting..." << endl;

	}
	file.close();
}
*/
void PWM::setup()
{
	write_all_value(0, 0);
	_write_byte_data(_MODE2, _OUTDRV);
	_write_byte_data(_MODE1, _ALLCALL);
	delayMicroseconds(5);
	int mode1 = _read_byte_data(_MODE1);
	mode1 = mode1 & ~_SLEEP;
	_write_byte_data(_MODE1, mode1);
	delayMicroseconds(5);
	_FREQUENCY = 60;
}

void PWM::_write_byte_data(int reg, int value)
{
	int error = 0;
	try
	{
		error = wiringPiI2CWriteReg8(_DEVICE, reg, value); //No proper Error Handling yet
	}
	catch (const std::exception&e)
	{
		cout << &e << endl;
		cout << error << endl;
		_check_i2c();
	}
}

int PWM::_read_byte_data(int reg)
{
	int value;
	try
	{
		value = wiringPiI2CReadReg8(_DEVICE, reg); //No proper Error Handling yet
	}
	catch (const std::exception&e)
	{
		cout << &e << endl;
		_check_i2c();
	}
	return value;
}

void PWM::_check_i2c()
{
	//TODO: Check I2C Instructions
}

int PWM::rt_frequency()
{
	return _FREQUENCY;
}

void PWM::frequency(int freq)
{
	_FREQUENCY = freq;
	double prescale_val = 25000000.0;
	prescale_val /= 4096.0;
	prescale_val /= float(freq);
	prescale_val -= 1.0;
	double prescale = floor(prescale_val + 0.5);
	int old_mode = _read_byte_data(_MODE1);
	int new_mode = (old_mode & 0x7F) | 0x10;
	_write_byte_data(_MODE1, new_mode);
	_write_byte_data(_PRESCALE, int(floor(prescale)));
	_write_byte_data(_MODE1, old_mode);
	delay(5);
	_write_byte_data(_MODE1, old_mode | 0x80);
}

void PWM::write(int channel, int on, int off)
{
	_write_byte_data(_LED0_ON_L + 4 * channel, on & 0xFF);
	_write_byte_data(_LED0_ON_H + 4 * channel, on >> 8);
	_write_byte_data(_LED0_OFF_L + 4 * channel, off & 0xFF);
	_write_byte_data(_LED0_OFF_H + 4 * channel, off >> 8);
}

void PWM::write_all_value(int on, int off)
{
	_write_byte_data(_ALL_LED_ON_L, on & 0xFF);
	_write_byte_data(_ALL_LED_ON_H, on >> 8);
	_write_byte_data(_ALL_LED_OFF_L, off & 0xFF);
	_write_byte_data(_ALL_LED_OFF_H, off >> 8);
}

double PWM::map(int x, int in_min, int in_max, int out_min, int out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


PWM::~PWM()
{
}
