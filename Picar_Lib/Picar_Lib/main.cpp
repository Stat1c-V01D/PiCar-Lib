#include <wiringPi.h>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

// LED-PIN - wiringPi-PIN 0 ist BCM_GPIO 17.
// Wir müssen bei der Initialisierung mit wiringPiSetupSys die BCM-Nummerierung verwenden.
// Wenn Sie eine andere PIN-Nummer wählen, verwenden Sie die BCM-Nummerierung, und
// aktualisieren Sie die Eigenschaftenseiten – Buildereignisse – Remote-Postbuildereignisbefehl 
// der den GPIO-Export für die Einrichtung für wiringPiSetupSys verwendet.
#define	LED	17

int main(void)
{
	wiringPiSetupGpio();

	pinMode(LED, INPUT);

	while (true)
	{
		digitalRead(LED);  // Ein
		delay(5000); // ms
	}
	return 0;
}