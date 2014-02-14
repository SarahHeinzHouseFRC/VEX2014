task watchDog()
{
	while(true)
	{
		if((vexRT[Btn6UXmtr2] == 1 && vexRT[Btn6DXmtr2] == 1) || (vexRT[Btn6U] == 1 && vexRT[Btn6D] == 1))
		{
			StopTask(driveMain);
			StopTask(armControlMain);
			StopTask(pistonControl);
			StopTask (liftReset);
			while((vexRT[Btn6UXmtr2] == 1 && vexRT[Btn6DXmtr2] == 1) || (vexRT[Btn6U] == 1 && vexRT[Btn6D] == 1))
			{
				StartTask(driveMain);
				StartTask(armControlMain);
				StartTask(pistonControl);
				StartTask(liftReset);
			}
		}
}
}
