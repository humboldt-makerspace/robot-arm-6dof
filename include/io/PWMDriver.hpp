#ifndef PWM_DRIVER_HPP
#define PWM_DRIVER_HPP

#include "system/Interface.hpp"

class PWMDriver {
private:
	/* functions */

public:
	/* variables */
	static int maxDuty;
	static double targetDuty[NUM_MOTORS];
	static double currentDuty[NUM_MOTORS];
	static double speed[NUM_MOTORS];

	/* functions */
	static void init (void);
	static void setDutyCycle (double duty, uint8_t channel);
};

#endif
