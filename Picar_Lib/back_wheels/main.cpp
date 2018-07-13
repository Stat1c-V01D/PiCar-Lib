#include <wiringPi.h>
#include "back_wheels.h"


int main(void)
{
	back_wheels bw = back_wheels();
	bw.forward();
	bw.speed(50);
	delay(1000);
	bw.stop();
}