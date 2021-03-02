#ifndef BT_SERIAL_HPP
#define BT_SERIAL_HPP

#include "system/Interface.hpp"

class BTSerial {
private:
	/* functions */

public:
	/* variables */
	static BluetoothSerial bt;
	static int index;
	static long int timeOut;

	/* functions */
	static String readPackage (void);
	static void processCommand (String cmd);
	static void sendString (String toSend);
};

#endif
