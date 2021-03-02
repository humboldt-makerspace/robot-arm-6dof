#include "io/PWMDriver.hpp"
#include "system/Interface.hpp"

int PWMDriver::maxDuty;
double PWMDriver::targetDuty[NUM_MOTORS];
double PWMDriver::currentDuty[NUM_MOTORS];
double PWMDriver::speed[NUM_MOTORS];

void PWMDriver::init (void)
{
	ledcSetup(CHANNEL_1, PWM_FREQUENCY, RESOLUTION_BITS);
	ledcSetup(CHANNEL_2, PWM_FREQUENCY, RESOLUTION_BITS);
	ledcSetup(CHANNEL_3, PWM_FREQUENCY, RESOLUTION_BITS);
	ledcSetup(CHANNEL_4, PWM_FREQUENCY, RESOLUTION_BITS);
	ledcSetup(CHANNEL_5, PWM_FREQUENCY, RESOLUTION_BITS);
	ledcSetup(CHANNEL_6, PWM_FREQUENCY, RESOLUTION_BITS);
	ledcAttachPin(PWM_PIN_1, CHANNEL_1);
	ledcAttachPin(PWM_PIN_2, CHANNEL_2);
	ledcAttachPin(PWM_PIN_3, CHANNEL_3);
	ledcAttachPin(PWM_PIN_4, CHANNEL_4);
	ledcAttachPin(PWM_PIN_5, CHANNEL_5);
	ledcAttachPin(PWM_PIN_6, CHANNEL_6);
	PWMDriver::maxDuty = pow(2.0, RESOLUTION_BITS);
	for (int i = 0; i < NUM_MOTORS; i++) {
		PWMDriver::targetDuty[i] = 0.0;
		PWMDriver::currentDuty[i] = 0.0;
	}
}

void PWMDriver::setDutyCycle (double duty, uint8_t channel)
{
	int intDuty = duty * PWMDriver::maxDuty;
	ledcWrite(channel, intDuty);
}
