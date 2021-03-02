#include "utils/Misc.hpp"
#include "system/Interface.hpp"

int Misc::charToInt (char c)
{
	int t = (int) c;
	if (t > 47 && t < 58) return t - 48;
	else return -1;
}

uint8_t Misc::jointToChannel (Joint joint)
{
	switch (joint) {
		case BASE: return CHANNEL_1;
		case ARM_1: return CHANNEL_2;
		case ARM_2: return CHANNEL_3;
		case ARM_3: return CHANNEL_4;
		case CLAMP_ROLL: return CHANNEL_5;
		case CLAMP_PITCH: return CHANNEL_6;
		default: return -1;
	}
}
