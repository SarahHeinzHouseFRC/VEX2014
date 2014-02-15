task watchDog()
{
	while(true)
	{
		if(overrideAll())
		{
			StopTask(driveMain);
			StopTask(armControlMain);
			StopTask(pistonControl);
			StopTask (liftReset);
			while(overrideAll())
			{
				StartTask(driveMain);
				StartTask(armControlMain);
				StartTask(pistonControl);
				StartTask(liftReset);
			}
		}
}
}
