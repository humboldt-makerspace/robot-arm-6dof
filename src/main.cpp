#include "includes.h"

void setup (void)
{
	Setup::init();
}

void loop (void)
{
	Interface::readButtons();
	BTSerial::processCommand(BTSerial::readPackage());
	// for (int i = 110; i < 126; i++) {
	// 	PWMDriver::setDutyCycle((double)i / 1000, CHANNEL_6);
	// 	Serial.println(i);
	// 	delay(1000);
	// }
}
