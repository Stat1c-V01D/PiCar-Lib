#include <wiringPi.h>
#include "TB6612.h"
// LED-PIN - wiringPi-PIN 0 ist BCM_GPIO 17.
// Wir m�ssen bei der Initialisierung mit wiringPiSetupSys die BCM-Nummerierung verwenden.
// Wenn Sie eine andere PIN-Nummer w�hlen, verwenden Sie die BCM-Nummerierung, und
// aktualisieren Sie die Eigenschaftenseiten � Buildereignisse � Remote-Postbuildereignisbefehl 
// der den GPIO-Export f�r die Einrichtung f�r wiringPiSetupSys verwendet.

int main(void)
{
	
}