#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  ,               sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  ,               sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           left,          tmotorVex393_MC29, PIDControl, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port3,           right,         tmotorVex393_MC29, PIDControl, reversed, driveRight, encoderPort, I2C_2)
#pragma config(Motor,  port4,           mainlift,      tmotorVex393_MC29, PIDControl, encoderPort, dgtl1)
#pragma config(Motor,  port5,           secondarylift, tmotorVex393_MC29, PIDControl, encoderPort, dgtl4)
#pragma config(Motor,  port6,           mobileloader1, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           mobileloader2, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           elbow,         tmotorVex393_MC29, PIDControl, encoderPort, I2C_3)
#pragma config(Motor,  port9,           intakelevel,   tmotorVex393_MC29, PIDControl, encoderPort, dgtl3)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define eblow1deg 10

//Last button state
bool lastraisearmbtn = false;
bool lastintakebtn = false;
bool lastdebugautobtn = false;

//Button press
bool raisearmbtnpressed = false;
bool intakebtnpressed = false;
bool debugautobtnpressed = false;

//mobileloader
bool loaderexpanded = false;

void buttonhandler()
{
	bool thisraisearm = (vexRT[Btn5U] == 1);
	bool thisintake = (vexRT[Btn6U] == 1);
	bool thisdebugauto = (vexRT[Btn7L] == 1);
	if(lastraisearmbtn){
		if(!thisraisearm){
			raisearmbtnpressed = true;
		}
	}
	if(lastintakebtn){
		if(!thisintake){
			intakebtnpressed = true;
		}
	}
	if(lastdebugautobtn){
		if(!thisdebugauto){
			debugautobtnpressed = true;
		}
	}
	lastraisearmbtn = thisraisearm;
	lastintakebtn = thisintake;
	lastdebugautobtn = thisdebugauto;
}

task main()
{
	while(1)
	{
		buttonhandler();
	}
}
