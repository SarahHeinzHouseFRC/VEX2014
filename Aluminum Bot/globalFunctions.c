// Driving
void driveAtSpeed(int rightSpeed, int leftSpeed)
{
	motor[driveRightBack]  = rightSpeed;
	motor[driveRightFront] = rightSpeed;
	motor[driveLeftBack]   = leftSpeed;
	motor[driveLeftFront]  = leftSpeed;
}




// Resetting sensors and stopping all motors
void resetDriveEncoders()
{
	nMotorEncoder[driveRightFront] = 0;
	nMotorEncoder[driveLeftFront] = 0;
}


void resetAllEncoders()
{
	nMotorEncoder[LiftLeft] = 0;
	nMotorEncoder[intakeLeft] = 0;
	nMotorEncoder[intakeRight] = 0;
	nMotorEncoder[driveRightFront] = 0;
	nMotorEncoder[driveLeftFront] = 0;
}


void resetLiftEncoderToValue(int value)
{
	nMotorEncoder[LiftLeft] = value;
	nMotorEncoder[LiftRight] = value;
}


void resetGyro()
{
	clearScreen();
	if(bIfiRobotDisabled)
	{                                            // Do full calibration if disabled
		displayLCDCenteredString(1, "Gyro In 3");
		wait10Msec(100);
		displayLCDCenteredString(1, "Gyro In 2");
		wait10Msec(100);
		displayLCDCenteredString(1, "Gyro In 1");
		wait10Msec(100);
		displayLCDCenteredString(1, "NOW");
		wait10Msec(100);
	}
	displayLCDCenteredString(1, "DO NOT TOUCH");
	SensorType[gyro] = sensorNone;
	SensorType[gyro] = sensorGyro;
	SensorFullCount[in2] = 3600000;

	if(bIfiRobotDisabled)
	{ displayLCDCenteredString(0, "CALIBRATING");
		wait1Msec(3000);
		displayLCDCenteredString(1, "Gyro Set");
		wait1Msec(500);
	}
	else
	{  displayLCDCenteredString(0, "PUSH BTN TO STOP");
		int millisec = 0;
		while(millisec < 1500)
		{
			if(overrideAll())      // Push button to eject from short calibration
				break;
			wait1Msec(1);
			millisec++;
		}
		if(!overrideAll())
		{
			displayLCDCenteredString(1, "Gyro Set Quick");
			wait1Msec(500);
		}
	}

}


void stopAllMotors()
{
	motor[driveLeftBack] = 0;
	motor[driveLeftFront] = 0;
	motor[driveRightBack] = 0;
	motor[driveRightFront] = 0;
	motor[LiftLeft] = 0;
	motor[LiftRight] = 0;
	motor[intakeRight] = 0;
	motor[intakeLeft] = 0;
	motor[rightArm1] = 0;
	motor[leftArm1] = 0;
}



// Arm
int armPosition()
{// Returns pot value
	return (SensorValue[potentiometer]);
}


void armAtSpeed(int speed)
{
	motor[rightArm1] = speed;
	motor[leftArm1]  = speed;
}


void stopArm()                  // This is to stop the arm motors.
{
	if(armPosition() > maxHeight + 200)
	{
		while(armPosition() > maxHeight + 200)
		{
			armAtSpeed(-armSpeed);
		}
	}
	if(armPosition() < 1900 && armPosition() > 700)      //Gives it a little power to keep the arm up
		armAtSpeed(20);
	else if(armPosition() < 2200 && armPosition() > 700) // Less power is needed twards the top
		armAtSpeed(10);
	else                          // Dont want to have it push itself over when it is near the top
		armAtSpeed(0);
}


void raiseArm()
{// Arm goes up.
	if(armPosition() > maxHeight + 200)
		armAtSpeed(-armSpeed);
	else if(armPosition() < maxHeight - 200)
		armAtSpeed(armSpeed);
	else if(armPosition() < maxHeight)
		armAtSpeed(50);
	else
		stopArm();
}


void lowerArm()
{	// Arm lowers
	if(armPosition() > slowdPosition)// Speed decreases as we near the bottom.
	{
		armAtSpeed(-armDownSpeed);
		} else if(armPosition() > zeroValue){
		armAtSpeed(-slowSpeed);
	}
	else{                             // If less than zero dont smash the arm
		stopArm();
	}
}


void positionArm(int position)
{// Positions arm to a specified place
	int times = 0;
	while(times < 2)
	{
		if (armPosition() < position )
		{
			while(armPosition() < position && vexRT[Btn6U] == 0 && vexRT[Btn6D] == 0){
				raiseArm();
			}
			stopArm();
		}
		else if (armPosition() > position)
		{
			int previous = armPosition();
			lowerArm();
			wait10Msec(1);
			while (armPosition() > position && armPosition() < previous){     // So that if it gets stuck going down it will stop,
				previous = armPosition();                                       // or at bottom it will automaticly break out of the loop
				lowerArm();                                                     // (manual break before)
				wait10Msec(1);
			}
			stopArm();
		}
		times++;
	}
	stopArm();
}



// Intake
void intakeAtSpeed(int speed)
{
	motor[intakeLeft] = speed;
	motor[intakeRight] = speed;
}



// Lift
void liftMove(int speed)
{
	motor[LiftLeft] = speed;
	motor[LiftRight]  = speed;
}


void positionLift(int position)
{
	if (nMotorEncoder[LiftLeft] > position )
	{
		while(nMotorEncoder[LiftLeft] > position)
			liftMove(-127);
	} else if (nMotorEncoder[LiftLeft] < position)
	{
		while (nMotorEncoder[LiftLeft]< position)
			liftMove(127);
	}
	liftMove(0);
}




void displayBatteryVoltage()
{
	clearScreen();

	//Display the Primary Robot battery voltage
	displayLCDString(0, 0, "Primary: ");
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
	displayNextLCDString(mainBattery);

	//Display the Backup battery voltage
	displayLCDString(1, 0, "Backup: ");
	sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V'); //Build the value to be displayed
	displayNextLCDString(backupBattery);
}
