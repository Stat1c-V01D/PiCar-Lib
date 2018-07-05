#include "PWM.h"
#include<wiringPi.h>
#include<time.h>
#include<math.h>
#include<string>
#include<fstream>
#include<stdio.h>
#include<iostream>

using namespace std;

PWM::PWM()
{
}

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

string PWM::_get_pi_ver()
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
				if (tmp_data.find("900092")) return "0";
				if (tmp_data.find()
			}

		}
		if line.startswith('Revision') :
			if line[11:-1] in self.RPI_REVISION_0 :
				return '0'
				elif line[11:-1] in self.RPI_REVISION_1_MODULE_B :
				return '1 Module B'
				elif line[11:-1] in self.RPI_REVISION_1_MODULE_A :
				return '1 Module A'
				elif line[11:-1] in self.RPI_REVISION_1_MODULE_BP :
				return '1 Module B+'
				elif line[11:-1] in self.RPI_REVISION_1_MODULE_AP :
				return '1 Module A+'
				elif line[11:-1] in self.RPI_REVISION_2 :
				return '2 Module B'
				elif line[11:-1] in self.RPI_REVISION_3 :
				return '3 Module B'
			else:
		print "Error. Pi revision didn't recognize, module number: %s" % line[11:-1]
			print 'Exiting...'
			quit()
	}
	catch (const std::exception&e)
	{
		file.close();
		cout << &e << endl;
		cout << "Exiting..." << endl;

	}
	file.close();
}

void PWM::setup()
{
}


PWM::~PWM()
{
}
