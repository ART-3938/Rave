#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     leftIR,         sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     rightIR,        sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoStandard)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Autonomous Mode Code Template
//
// This file contains a template for simplified creation of an autonomous program for an TETRIX robot
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.

int dist; // distance from robot (either front center or left center) to the beacon
float angle;  // angle from robot's center to the beacon
	// FIND ZONE ANGLE EDGES!!!! PREFERABLY ARRAY OF FLOATS
	// vector currentHeading; // this is the current heading vector of the robot


float findBeaconAngle();
float findLeftAngle();
float findRightAngle();
float findBackAngle();
void println(int line, string s);



/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of autonomous mode, you may want to perform some initialization on your robot.
// Things that might be performed during initialization include:
//   1. Move motors and servos to a preset position.
//   2. Some sensor types take a short while to reach stable values during which time it is best that
//      robot is not moving. For example, gyro sensor needs a few seconds to obtain the background
//      "bias" value.
//
// In many cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
	angle = findBeaconAngle();
	dist = 0; //find distance
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the autonomous robot operation. Customize as appropriate for
// your specific robot.
//
// The types of things you might do during the autonomous phase (for the 2008-9 FTC competition)
// are:
//
//   1. Have the robot follow a line on the game field until it reaches one of the puck storage
//      areas.
//   2. Load pucks into the robot from the storage bin.
//   3. Stop the robot and wait for autonomous phase to end.
//
// This simple template does nothing except play a periodic tone every few seconds.
//
// At the end of the autonomous period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
	initializeRobot();

	waitForStart(); // Wait for the beginning of autonomous phase.

  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////
  ////                                                   ////
  ////    Add your robot specific autonomous code here.  ////
  ////                                                   ////
  ///////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////

	findBeaconAngle();
	while (true)
	{
		// track and move (SMOOTHLY!?!?)
	}
}

float findBeaconAngle()
{
	float x = 1.0; //distance between sensors in inches

	//find zones on left and right eyes
	int Lzone = HTIRS2readDCDir(leftIR);
	int Rzone = HTIRS2readDCDir(rightIR);
	while (Lzone < 0)
	{
		// rotate and find beacon
	}
	while (Rzone < 0)
	{
		// rotate and find beacon
	}
	println(4, "LZ " + Lzone + " RZ " + Rzone);

	// Rotate servos left and right to accurately locate signal source
	// Left "eye" angle
	// Right "eye" angle

	// Math to find angle to the center front of the robot

	return -1;
}

// Working??!?!?!!
float findAngle(Sensor eye, Servo eyeMuscle){
	// copy right angle code
	// GENERALIZE??!?!
	int zone = HTIRS2readDCDir(eye);

	float dAl = 0; // change in servo rotation angle to the left
	while (HTIRS2readDCDir(eye) == zone){
		// rotate servo left in small increments
		dAl += 1;  // increment by angle change
	}

	while (HTIRS2readDCDir(eye) != zone){
		// rotate back into the zone
	}

	float dAr = 0;
	while (HTIRS2readDCDir(eye) == zone){
		// rotate servo right in small increments
		dAr += 1; // increment by angle change
	}

	// dAl = size of zone - dAl; // dAl is a "complement" of dAr - use to find more accurate
	float avgdA = (dAl + dAr)/2; // average displacement to each side

	float angle = 0; // zone extreme - avgdA
	return angle;
}

// Find the "exact" angle of the beacon relative to the right IR beacon's normal axis
float findRightAngle(){
	int zone = HTIRS2readDCDir(rightIR);

	float dAl = 0; // change in servo rotation angle to the left
	while (HTIRS2readDCDir(rightIR) == zone){
		// rotate servo left in small increments
		dAl += 1;
	}

	while (HTIRS2readDCDir(rightIR) != zone){
		// rotate back into the zone
	}

	float dAr = 0;
	while (HTIRS2readDCDir(rightIR) == zone){
		// rotate servo right in small increments
		dAr += 1;
	}

	// dAl = size of zone - dAl // dAl is a "complement" of dAr - use to find more accurate
	float avgdA = (dAl + dAr)/2; // average displacement to each side

	float angle = 0; // zone extreme - avgdA
	return angle;
}

void println(int line, string s){
	nxtDisplayCenteredTextLine(line, s);
}
