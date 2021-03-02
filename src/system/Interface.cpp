#include "system/Interface.hpp"

boolean Interface::btnPressed;
boolean Interface::button;

void Interface::readButtons (void)
{
	button = digitalRead(RED_BUTTON_PIN);
	if (!button) btnPressed = true;
	if (button && btnPressed) {
		btnPressed = false;
		PWMDriver::targetDuty[0] += 0.03;
		if (PWMDriver::targetDuty[0] > 0.124) PWMDriver::targetDuty[0] = 0.0;
	}
}
