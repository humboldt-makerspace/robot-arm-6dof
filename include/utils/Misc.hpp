#ifndef MISC_HPP
#define MISC_HPP

#include "constants.h"
#include "Arduino.h"

class Misc {
private:

public:
	/* functions */
	static int charToInt (char c);
	static uint8_t jointToChannel (Joint joint);
};

#endif
