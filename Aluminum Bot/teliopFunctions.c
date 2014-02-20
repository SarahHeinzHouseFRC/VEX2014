task driveMain()
{while(true)
	{
		if(abs(vexRT[Ch3]) > threshold && abs(vexRT[Ch2]) > threshold)
			driveAtSpeed((vexRT[Ch2]),(vexRT[Ch3]));
		else if(vexRT[Ch3] > (100 - threshold) && vexRT[Ch2] > (100 - threshold))
			driveAtSpeed(127,127);
		else if(vexRT[Ch3] < (-100 + threshold) && vexRT[Ch2] < (-100 + threshold))
			driveAtSpeed(-127,-127);
		else if(abs(vexRT[Ch3]) > threshold)
			driveAtSpeed(0,vexRT[Ch3]);
		else if(abs(vexRT[Ch2]) > threshold)
			driveAtSpeed(vexRT[Ch2],0);
		else
			driveAtSpeed(0,0);
	}
}


void intakeMain()
{// Intake for 1 controller.
	if(vexRT[Btn5D] == 1 && vexRT[Btn5U] == 0)
		intakeAtSpeed(intakeSpeed);// Intake roller inward.
	else  if(vexRT[Btn5D]==0&&vexRT[Btn5U]==1)
		intakeAtSpeed(-intakeSpeed);// Intake roller outward.
	else
		intakeAtSpeed(0);	// Stop intake roller movement.
}


void climbRaiseMain()
{
	stopAllMotors();
	liftMove(-127);
	positionArm(scoreHeight);
	positionLift(liftExtendedTicks);
	while(true)
	{
		if(vexRT[Btn7L] == 1)
		{ stopAllMotors();
			while(vexRT[Btn7L] == 1)
			{
				if(armPosition() > maxHeight + 200)
					while(armPosition() > maxHeight - 200)
					armAtSpeed(-armSpeed);
				else
					armAtSpeed(127);
			}
			armAtSpeed(1);
			positionLift(-2000);
			liftMove(127);
			wait10Msec(300);
			liftMove(0);
		}
		else
		{}
	}
}



task armControlMain()
{
	while(true)
	{
		if(armPosition() > maxHeight + 200)
			armAtSpeed(-armSpeed);
		else if(vexRT[Btn7D] || vexRT[Btn7U] || vexRT[Btn7R] || vexRT[Btn7L]
			|| vexRT[Btn8D] || vexRT[Btn8U] || vexRT[Btn8R] || vexRT[Btn8L]
		|| vexRT[Btn6U] || vexRT[Btn6D] || vexRT[Btn5D] || vexRT[Btn5U])
		{
			if(vexRT[Btn6U] == 1 && vexRT[Btn6D] == 0 && vexRT[Btn8U]== 0 && vexRT[Btn8D]== 0){
				raiseArm();
				}	else if(vexRT[Btn6U] == 0 && vexRT[Btn6D] == 1 && vexRT[Btn8U] == 0 && vexRT[Btn8D] == 0 && vexRT[Btn8R] == 0){
				lowerArm();
				} else if(vexRT[Btn6U] == 0 && vexRT[Btn6D] == 0 && vexRT[Btn8U] == 1 && vexRT[Btn8D] == 0 && vexRT[Btn8R] == 0){
				positionArm(scoreHeight);
			} else if(vexRT[Btn6U] == 0 && vexRT[Btn6D] == 0 && vexRT[Btn8U] == 0 && vexRT[Btn8D] == 1 && vexRT[Btn8R] == 0)
				positionArm(zeroValue);
			else if(vexRT[Btn7R] == 1)
				positionLift(liftDriveTicks);
			else if(vexRT[Btn7U] == 1)
				climbRaiseMain();
			else if(vexRT[Btn8U] == 1)
				positionArm(scoreHeight);
			else if(vexRT[Btn8D] == 1)
				positionArm(zeroValue);
			else if(vexRT[Btn7R] == 1)
				positionLift(liftDriveTicks);
			else if(vexRT[Btn7U] == 1)
				climbRaiseMain();
			else
			stopArm();
		}
		else
			stopArm();
	}

}

void individualLiftControlXmit2()
{
	if	(vexRT[Btn7RXmtr2] == 1)
					motor[LiftLeft] = 50;
				else if	(vexRT[Btn7LXmtr2] == 1)
					motor[LiftLeft] = -50;
				else
					motor[LiftLeft] = -1vexRT[Ch3Xmtr2];

		if	(vexRT[Btn8RXmtr2] == 1)
					motor[LiftRight] = 50;
				else if	(vexRT[Btn8LXmtr2] == 1)
					motor[LiftRight] = -50;
				else
					motor[LiftRight] = -vexRT[Ch2Xmtr2];
			}


			task liftReset()
{
while(true)
{
	if (nVexRCReceiveState & vrXmit2)
{
			if((vexRT[Btn7DXmtr2] == 1) && (vexRT[Btn7UXmtr2] == 1))
		{
			while(vexRT[Btn7DXmtr2] || (vexRT[Btn7UXmtr2])
			{
				individualLiftControlXmit2();
			}
			resetLiftEncoderToValue(0);
		}
		else if((vexRT[Btn8DXmtr2] == 1) && (vexRT[Btn8UXmtr2] == 1))
		{
			while(vexRT[Btn8DXmtr2] || (vexRT[Btn8UXmtr2])
			{
				individualLiftControlXmit2();
			}
			resetLiftEncoderToValue(liftDriveTicks);
		}
	}
	else
	{
		wait10Msec(100);
	}
	wait10Msec(10);

}
}
