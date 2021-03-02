#ifndef MOTION_CONTROLLER_HPP
#define MOTION_CONTROLLER_HPP

#include "Arduino.h"
#include "constants.h"

class MotionController {
private:

public:
	/* functions */
	static void moveJoints ();
	static void setTarget (Joint joint, double duty);
	static void nextDuty (double target, double* current, double* speed);
};

#endif
