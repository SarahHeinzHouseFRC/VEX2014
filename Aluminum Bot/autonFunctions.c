// Encoder Driven
void driveAtSpeedForTicks(int driveSpeed, int distanceTicks)
{
	resetDriveEncoders();
	while(abs(nMotorEncoder[driveRightFront]) < distanceTicks){
		driveAtSpeed(driveSpeed, driveSpeed);
	}
	driveAtSpeed(0, 0);
}


void turnAtSpeedForTicks(int leftSpeed, int rightSpeed, int ticks)
{
	resetDriveEncoders();
	while(((abs(nMotorEncoder[driveRightFront]) + abs(nMotorEncoder[driveLeftFront]))/2) < ticks)
		driveAtSpeed(rightSpeed, leftSpeed);
	driveAtSpeed(0, 0);
}








// Gyro
void turnAtSpeedToGyroAlowed(int leftSpeed, int rightSpeed, int position)
{
	int startPosition = SensorValue[gyro];
	int targetPosition = startPosition + position;
	while((SensorValue[gyro] < targetPosition) || (SensorValue[gyro]  > targetPosition))
		driveAtSpeed(rightSpeed, leftSpeed);
	driveAtSpeed(0, 0);
	wait10Msec(1);
	while(SensorValue[gyro] < targetPosition || SensorValue[gyro]  > targetPosition)
			driveAtSpeed(-rightSpeed/2, -leftSpeed/2);
	driveAtSpeed(0, 0);
	wait10Msec(1);
		while(SensorValue[gyro] < targetPosition || SensorValue[gyro]  > targetPosition)
		driveAtSpeed(rightSpeed/3, leftSpeed/3);
	driveAtSpeed(0, 0);
}






// Ultrasonic
void driveAtSpeedUntilDistanceFront(int speed, int distance)
{
	if(speed > 0)              // If positive speed
		while(SensorValue(frontSonar) > distance || SensorValue(frontSonar) == -1)
			driveAtSpeed(speed, speed);
	else if(speed < 0)                    // If negative speed
		while(SensorValue(frontSonar) < distance)
		     driveAtSpeed(speed, speed);
		    driveAtSpeed(0, 0);
}



void driveAtSpeedUntilDistanceRear(int speed, int distance)
{
	if(speed > 0)              // If positive speed
	while(SensorValue(rearSonar) < distance)
			driveAtSpeed(speed, speed);
	else if(speed < 0)                    // If negative speed
		while(SensorValue(rearSonar) > distance || SensorValue(rearSonar) == -1)
					driveAtSpeed(speed, speed);
			   driveAtSpeed(0, 0);
}
