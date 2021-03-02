#include "utils/MotionController.hpp"
#include "system/Interface.hpp"

void MotionController::moveJoints ()
{
	for (int i = 0; i < 1; i++) {
		MotionController::nextDuty(PWMDriver::targetDuty[i], &PWMDriver::currentDuty[i], &PWMDriver::speed[i]);
		uint8_t channel = Misc::jointToChannel((Joint)i);
		PWMDriver::setDutyCycle(PWMDriver::currentDuty[i], channel);
		Serial.println(PWMDriver::speed[i]);
	}
	delay(10);
}

void MotionController::setTarget (Joint joint, double duty)
{
	PWMDriver::targetDuty[joint] = duty;
}

void MotionController::nextDuty (double target, double* current, double* speed)
{
	double way = target - *current;
	Serial.print("way: ");
	Serial.println(way);
	if (way >= 0) {
		if (*speed > sqrt(2 * ACCELERATION * way)) {
			*speed = sqrt(2 * ACCELERATION * way);
		}
		else if (*speed < MAX_SPEED) {
			*speed += ACCELERATION;
		}
	}
	else {
		if (*speed < -sqrt(2 * ACCELERATION * way)) {
			*speed = -sqrt(2 * ACCELERATION * way);
		}
		else if (*speed > -MAX_SPEED) {
			*speed -= ACCELERATION;
		}
	}
	if (abs(way) < CLOSE_THRESHOLD) {
		*current = target;
		*speed = 0.0;
	}
	else *current += *speed;
}
