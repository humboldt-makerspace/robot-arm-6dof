#ifndef CONSTANTS_H
#define CONSTANTS_H

/* WiFi and UDP */
#define MAX_PACKET_SIZE			100

/* time parameters */
#define TIME_ZONE				1
#define DST						1

/* motor constants */
#define PWM_PIN_1				26
#define PWM_PIN_2				25
#define PWM_PIN_3				33
#define PWM_PIN_4				32
#define PWM_PIN_5				35
#define PWM_PIN_6				34
#define CHANNEL_1				1
#define CHANNEL_2				2
#define CHANNEL_3				3
#define CHANNEL_4				4
#define CHANNEL_5				5
#define CHANNEL_6				6
#define PWM_FREQUENCY			50
#define RESOLUTION_BITS			12.0
#define NUM_MOTORS				6

/* controller */
#define MAX_SPEED				0.005
#define ACCELERATION			0.0001
#define CLOSE_THRESHOLD			0.001

/* buttons */
#define RED_BUTTON_PIN			12

/* serial communication */
#define BAUD_RATE				115200
#define CARRIAGE_RETURN			13
#define LINE_FEED				10

/* motion commands */
#define FIRST_JOINT_CW			"7onecw\r\n"
#define FIRST_JOINT_CCW			"8oneccw\r\n"
#define SECOND_JOINT_CW			"7twocw\r\n"
#define SECOND_JOINT_CCW		"8twoccw\r\n"
#define THIRD_JOINT_CW			"7thrcw\r\n"
#define THIRD_JOINT_CCW			"8thrccw\r\n"
#define FOURTH_JOINT_CW			"8fourcw\r\n"
#define FOURTH_JOINT_CCW		"9fourccw\r\n"
#define FIFTH_JOINT_CW			"8fivecw\r\n"
#define FIFTH_JOINT_CCW			"9fiveccw\r\n"
#define SIXTH_JOINT_CW			"7sixcw\r\n"
#define SIXTH_JOINT_CCW			"8sixccw\r\n"

/* bt parameters */
#define BT_TIMEOUT				1000

/* robot joints */
typedef enum joints {
	BASE, ARM_1, ARM_2, ARM_3, CLAMP_ROLL, CLAMP_PITCH
} Joint;

#endif
