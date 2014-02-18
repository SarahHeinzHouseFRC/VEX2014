


void retractPistons()
{
	SensorValue[solenoid1] = true;
	SensorValue[solenoid2] = false;
	pistonState = 0;
	wait10Msec(50);
	SensorValue[solenoid1] = false;
	SensorValue[solenoid2] = false;
	pistonState = 1;
}

void changePistonState()
{
	if(pistonState == 0 || pistonState == 1)
{
	pistonState = 2;
  SensorValue[solenoid1] = false;
	SensorValue[solenoid2] = true;
}
else if(pistonState == 2)
	{
	retractPistons();
 }
}


task pistonControl()
{
	while(true)
	{
		if(vexRT[Btn8L] == 1)
{
changePistonState();
while(vexRT[Btn8L] == 1)
{}
}
	}


}
