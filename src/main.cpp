#include "includes.h"

void setup ()
{
	Setup::init();
}

void loop ()
{
	Interface::readButtons();
	MotionController::moveJoints();
	//BTSerial::processCommand(BTSerial::readPackage());
	// for (int i = 0; i < 125; i++) {
	// 	PWMDriver::setDutyCycle(((double)i) / 1000, CHANNEL_1);
	// 	if (i == 0) delay(3000);
	// 	else delay(100);
	// 	char intStr[10];
	// 	itoa(i, intStr, 10);
	// 	String str = String(intStr);
	// 	BTSerial::sendString(str);
	// 	//i += 9;
	// }

}
