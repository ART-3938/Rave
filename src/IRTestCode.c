#pragma config(Hubs,  S1, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IR,             sensorI2CCustom)
#pragma config(Servo,  srvo_S1_C1_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "drivers/hitechnic-irseeker-v2.h"

int zones [9] = { 255, 248, 244, 170, 166, 95, 87, 15, 11 };

//
//
//
//
//

task main()
{
	int middle = 256/2;
	servo[servo1] = 0;
	getJoystickSettings(joystick);

	tHTIRS2DSPMode _mode = DSP_1200;

	HTIRS2setDSPMode(IR, _mode);

	int dir = HTIRS2readDCDir(IR);

	bool buttonpressed = false;

	while(true){
		if(!buttonpressed)
		{
			if(joystick.joy1_TopHat == 2)
			{
				servo[servo1] = zones[dir - 1];
				buttonpressed = true;
			}
			else if(joystick.joy1_TopHat == 6)
			{
				servo[servo1] = zones[dir + 1];
				buttonpressed = true;
			}
			else if(joystick.joy1_TopHat == 0)
			{
				servo[servo1] = servo[servo1] - 1;
				buttonpressed = true;
			}
			else if(joystick.joy1_TopHat == 4)
			{
				servo[servo1] = servo[servo1] + 1;
				buttonpressed = true;
			}
		}
		else if (buttonpressed && (joystick.joy1_TopHat != 2 && joystick.joy1_TopHat != 6))
		{
			buttonpressed = false;
		}

		if(joy1Btn(1) == 1)
		{
			servo[servo1] = 128;
		}
		else if (joy1Btn(2) == 1)
		{
			servo[servo1] = 0;
		}
		else if (joy1Btn(3) == 1)
		{
			servo[servo1] = 255;
		}

		string hi = "hi";
		nxtDisplayString(1, hi);

		dir = HTIRS2readDCDir(IR);
		nxtDisplayString(2, "%d", dir);

		nxtDisplayString(3, "%d", servo[servo1]);

	}
}
