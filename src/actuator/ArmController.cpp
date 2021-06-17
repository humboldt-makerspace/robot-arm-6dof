#include "actuator/ArmController.hpp"
#include "system/Interface.hpp"

void ArmController::drive (Joint joint, DriveMode mode)
{
	switch (joint) {
		case BASE: {
			switch (mode) {
				case IDLE: {
					PWMDriver::setDutyCycle(BASE_IDLE, CHANNEL_1);
					break;
				}
				case FORWARD: {
					PWMDriver::setDutyCycle(BASE_FWD, CHANNEL_1);
					break;
				}
				case BACKWARD: {
					PWMDriver::setDutyCycle(BASE_REV, CHANNEL_1);
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case ARM_1: {
			switch (mode) {
				case IDLE: {
					PWMDriver::setDutyCycle(BASE_IDLE, CHANNEL_2);
					break;
				}
				case FORWARD: {
					PWMDriver::setDutyCycle(BASE_FWD, CHANNEL_2);
					break;
				}
				case BACKWARD: {
					PWMDriver::setDutyCycle(BASE_REV, CHANNEL_2);
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case ARM_2: {
			switch (mode) {
				case IDLE: {
					PWMDriver::setDutyCycle(BASE_IDLE, CHANNEL_3);
					break;
				}
				case FORWARD: {
					PWMDriver::setDutyCycle(BASE_FWD, CHANNEL_3);
					break;
				}
				case BACKWARD: {
					PWMDriver::setDutyCycle(BASE_REV, CHANNEL_3);
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case ARM_3: {
			switch (mode) {
				case IDLE: {
					PWMDriver::setDutyCycle(BASE_IDLE, CHANNEL_4);
					break;
				}
				case FORWARD: {
					PWMDriver::setDutyCycle(BASE_FWD, CHANNEL_4);
					break;
				}
				case BACKWARD: {
					PWMDriver::setDutyCycle(BASE_REV, CHANNEL_4);
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case CLAMP_ROLL: {
			switch (mode) {
				case IDLE: {
					PWMDriver::setDutyCycle(CLAMP_R_IDLE, CHANNEL_5);
					break;
				}
				case FORWARD: {
					PWMDriver::setDutyCycle(CLAMP_R_FWD, CHANNEL_5);
					break;
				}
				case BACKWARD: {
					PWMDriver::setDutyCycle(CLAMP_R_REV, CHANNEL_5);
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case CLAMP_PITCH: {
			switch (mode) {
				case IDLE: {
					PWMDriver::setDutyCycle(CLAMP_P_IDLE, CHANNEL_6);
					break;
				}
				case FORWARD: {
					PWMDriver::setDutyCycle(CLAMP_P_OPEN, CHANNEL_6);
					break;
				}
				case BACKWARD: {
					PWMDriver::setDutyCycle(CLAMP_P_CLOSE, CHANNEL_6);
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		default: {
			break;
		}
	}
}
