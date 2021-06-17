#include "io/BTSerial.hpp"
#include "system/Interface.hpp"

BluetoothSerial BTSerial::bt;
int BTSerial::index = 0;
long int BTSerial::timeOut = 0;

String BTSerial::readPackage (void)
{
	String myData = "";
	BTSerial::index = 0;
	while (BTSerial::bt.available() || BTSerial::index > 0) {
		if (BTSerial::bt.available()) {
			char inc = BTSerial::bt.read();
			myData += inc;
			if (isDigit(inc)) {
				BTSerial::index = Misc::charToInt(inc) + 1;
				timeOut = millis();
			}
			BTSerial::index--;
		}
		if (millis() - timeOut > BT_TIMEOUT) break;
	}
	return myData;
}

void BTSerial::sendString (String s)
{
	for (int i = 0; i < s.length(); i++) {
		uint8_t tmp = (uint8_t) s.charAt(i);
		BTSerial::bt.write(tmp);
		delay(5);
	}
	BTSerial::bt.write(CARRIAGE_RETURN);
	BTSerial::bt.write(LINE_FEED);
}

void BTSerial::processCommand (String cmd)
{
	if (cmd.isEmpty()) return;
	cmd.toLowerCase();
	if (cmd == FIRST_JOINT_CW) {
		ArmController::drive(BASE, FORWARD);
		delay(STEP_DURATION);
		ArmController::drive(BASE, IDLE);
		Serial.println("rotating first joint clockwise");
	}
	else if (cmd == FIRST_JOINT_CCW) {
		ArmController::drive(BASE, BACKWARD);
		delay(STEP_DURATION);
		ArmController::drive(BASE, IDLE);
		Serial.println("rotating first joint counter-clockwise");
	}
	else if (cmd == SECOND_JOINT_CW) {
		ArmController::drive(ARM_1, FORWARD);
		delay(STEP_DURATION);
		ArmController::drive(ARM_1, IDLE);
		Serial.println("rotating second joint clockwise");
	}
	else if (cmd == SECOND_JOINT_CCW) {
		ArmController::drive(ARM_1, BACKWARD);
		delay(STEP_DURATION);
		ArmController::drive(ARM_1, IDLE);
		Serial.println("rotating second joint counter-clockwise");
	}
	else if (cmd == THIRD_JOINT_CW) {
		ArmController::drive(ARM_2, FORWARD);
		delay(STEP_DURATION);
		ArmController::drive(ARM_2, IDLE);
		Serial.println("rotating third joint clockwise");
	}
	else if (cmd == THIRD_JOINT_CCW) {
		ArmController::drive(ARM_2, BACKWARD);
		delay(STEP_DURATION);
		ArmController::drive(ARM_2, IDLE);
		Serial.println("rotating third joint counter-clockwise");
	}
	else if (cmd == FOURTH_JOINT_CW) {
		ArmController::drive(ARM_3, FORWARD);
		delay(STEP_DURATION);
		ArmController::drive(ARM_3, IDLE);
		Serial.println("rotating fourth joint clockwise");
	}
	else if (cmd == FOURTH_JOINT_CCW) {
		ArmController::drive(ARM_3, BACKWARD);
		delay(STEP_DURATION);
		ArmController::drive(ARM_3, IDLE);
		Serial.println("rotating fourth joint counter-clockwise");
	}
	else if (cmd == FIFTH_JOINT_CW) {
		ArmController::drive(CLAMP_ROLL, FORWARD);
		delay(STEP_DURATION);
		ArmController::drive(CLAMP_ROLL, IDLE);
		Serial.println("rotating fifth joint clockwise");
	}
	else if (cmd == FIFTH_JOINT_CCW) {
		ArmController::drive(CLAMP_ROLL, BACKWARD);
		delay(STEP_DURATION);
		ArmController::drive(CLAMP_ROLL, IDLE);
		Serial.println("rotating fifth joint counter-clockwise");
	}
	else if (cmd == SIXTH_JOINT_CW) {
		ArmController::drive(CLAMP_PITCH, FORWARD);
		delay(STEP_DURATION);
		ArmController::drive(CLAMP_PITCH, IDLE);
		Serial.println("rotating sixth joint clockwise");
	}
	else if (cmd == SIXTH_JOINT_CCW) {
		ArmController::drive(CLAMP_PITCH, BACKWARD);
		delay(STEP_DURATION);
		ArmController::drive(CLAMP_PITCH, IDLE);
		Serial.println("rotating sixth joint counter-clockwise");
	}
	else {
		Serial.print("unknown command, read: ");
		Serial.println(cmd);
	}
}
