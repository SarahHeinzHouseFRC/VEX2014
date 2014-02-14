void blueRear()
{ retractPistons();
	SensorValue[gyro] = 0;
	intakeAtSpeed(127);
	driveAtSpeedUntilDistanceFront(127, 220);
	wait10Msec(10);
	driveAtSpeedUntilDistanceFront(-127, 250);
	intakeAtSpeed(0);                            // back up from wall
	pointTurnPID(-900);     // turn to balls
	driveAtSpeedUntilDistanceRear(127, 650);     // to ball 1
	pointTurnPID(-1800);     // twards ball
	driveAtSpeedUntilDistanceRear(127, 750);    // to bump, 1st ball
	intakeTicks = nMotorEncoder(intakeLeft);
	intakeAtSpeed(-127);/////////////////////////////////////////////////////
	positionArm(800);
	while(nMotorEncoder(intakeLeft) > intakeTicks - 170)
	 intakeAtSpeed(-127);
	pointTurnPID(-900);
	intakeAtSpeed(0);
	driveAtSpeedUntilDistanceRear(127, 1000);
	pointTurnPID(-1800);
	changePistonState();
	driveAtSpeedUntilDistanceRear(127, 1500);
  //driveAtSpeed(127, 127);
  //positionArm(1300);
  //driveAtSpeedUntilDistanceRear(127, 1900);

}
void blueBigBalls()
{ retractPistons();
	SensorValue[gyro] = 0;
	driveAtSpeed(-127,-127);
	wait10Msec(100);
	driveAtSpeedUntilDistanceRear(-127, 1400);
	driveAtSpeed(-50,-50);
	positionLift(liftDriveTicks);
	driveAtSpeedForTicks(127, 300);
	pointTurnPID(900);     // turn to balls
	driveAtSpeedUntilDistanceFront(-127, 1000);   // to ball 1
	pointTurnPID(0);     // twards ball
	driveAtSpeedForTicks(-127, 200);
	driveAtSpeed(-50,-50);
  wait10Msec(50);
	driveAtSpeedForTicks(127, 200);
	pointTurnPID(900);
	changePistonState();
	driveAtSpeedUntilDistanceFront(127, 600);
	pointTurnPID(1800);
	driveAtSpeedForTicks(127, 1300);
	driveAtSpeedUntilDistanceFront(127, 800);
	driveAtSpeed(50,50);
	positionArm(scoreHeight);
	driveAtSpeed(0,0);

	//driveAtSpeedUntilDistanceFront(127, 800);
	//pointTurnPID(2250);
	//driveAtSpeed(50,50);
	//intakeAtSpeed(-127);

}

void redBigballs()
{ retractPistons();
	SensorValue[gyro] = 0;
	driveAtSpeed(-127,-127);
	wait10Msec(100);
	driveAtSpeedUntilDistanceRear(-127, 1400);
	driveAtSpeed(-50,-50);
	positionLift(liftDriveTicks);
	driveAtSpeedForTicks(127, 300);
	pointTurnPID(-900);     // turn to balls
	driveAtSpeedUntilDistanceFront(-127, 1000);   // to ball 1
	pointTurnPID(0);     // twards ball
	driveAtSpeedForTicks(-127, 200);
	driveAtSpeed(-50,-50);
  wait10Msec(50);
	driveAtSpeedForTicks(127, 200);
	pointTurnPID(-900);
	changePistonState();
	driveAtSpeedUntilDistanceFront(127, 600);
	pointTurnPID(-1800);
	driveAtSpeedForTicks(127, 1300);
	driveAtSpeedUntilDistanceFront(127, 800);
	driveAtSpeed(50,50);
	positionArm(scoreHeight);
	driveAtSpeed(0,0);

	//driveAtSpeedUntilDistanceFront(127, 800);
	//pointTurnPID(2250);
	//driveAtSpeed(50,50);
	//intakeAtSpeed(-127);

}





void blueSkills()
{
SensorValue[gyro] = 0;
	intakeAtSpeed(127);
	driveAtSpeedUntilDistanceFront(127, 220);
	wait10Msec(10);
	driveAtSpeedUntilDistanceFront(-127, 250);
	intakeAtSpeed(0);                            // back up from wall
	turnAtSpeedToGyroAlowed(100,-100, 900);      // turn to balls
	driveAtSpeedUntilDistanceRear(127, 650);     // to ball 1
	turnAtSpeedToGyroAlowed(100,-100, 900);     // twards ball
	driveAtSpeedUntilDistanceRear(127, 750);    // to bump, 1st ball
	intakeAtSpeed(-127);/////////////////////////////////////////////////////
	positionArm(880);
	wait10Msec(100);
	turnAtSpeedToGyroAlowed(-100,100, -900);
	driveAtSpeedUntilDistanceRear(127, 1000);
	turnAtSpeedToGyroAlowed(100,-100, 900);
	changePistonState();
	intakeAtSpeed(0);
	driveAtSpeedUntilDistanceRear(127, 1500);
driveAtSpeed(100, 100);
positionArm(scoreHeight);
wait10Msec(100);
}






void redRear()
{
	retractPistons();
	SensorValue[gyro] = 0;
	intakeAtSpeed(127);
	driveAtSpeedUntilDistanceFront(127, 220);
	wait10Msec(10);
	driveAtSpeedUntilDistanceFront(-127, 250);
	intakeAtSpeed(0);                            // back up from wall
	pointTurnPID(900);     // turn to balls
	driveAtSpeedUntilDistanceRear(127, 650);     // to ball 1
	pointTurnPID(1800);     // twards ball
	driveAtSpeedUntilDistanceRear(127, 750);    // to bump, 1st ball
	intakeTicks = nMotorEncoder(intakeLeft);
	intakeAtSpeed(-127);/////////////////////////////////////////////////////
	positionArm(800);
	while(nMotorEncoder(intakeLeft) > intakeTicks - 170)
	 intakeAtSpeed(-127);
	pointTurnPID(900);
	intakeAtSpeed(0);
	driveAtSpeedUntilDistanceRear(127, 1000);
	pointTurnPID(1800);
	changePistonState();
	driveAtSpeedUntilDistanceRear(127, 1500);
  driveAtSpeed(127, 127);
  positionArm(1300);
  driveAtSpeedUntilDistanceRear(127, 1900);
}







void dump()
{
	positionLift(liftDriveTicks);
	intakeAtSpeed(-127);
	wait10Msec(200);
	intakeAtSpeed(0);
}
