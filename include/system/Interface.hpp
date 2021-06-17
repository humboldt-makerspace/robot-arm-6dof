#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "constants.h"
#include "Arduino.h"
#include "WiFi.h"
#include "WiFiUdp.h"
#include "custom.h"
#include "BluetoothSerial.h"
#include <string>
#include <iostream>

#include "io/UDPManager.hpp"
#include "io/Parser.hpp"
#include "io/BTSerial.hpp"
#include "actuator/PWMDriver.hpp"
#include "actuator/ArmController.hpp"
#include "utils/AngleMapping.hpp"
#include "utils/MotionController.hpp"
#include "utils/Misc.hpp"

class Interface {
private:
	/* variables */

	/* functions */

public:
	/* variables */
	static boolean btnPressed;
	static boolean button;

	/* functions */
	static void readButtons (void);
};

#endif
