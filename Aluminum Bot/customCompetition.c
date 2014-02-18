void allMotorsOff();
void allTasksStop();
void pre_auton();
void clearScreen();
bool overrideAll();
task autonomous();
task usercontrol();


int nTimeXX = 0;
bool bStopTasksBetweenModes = true;


static void displayTime();

task main()
{
	pre_auton();

	while (true)
	{
		clearScreen();

		while (bIfiRobotDisabled)
		{
			clearScreen();
			bool toggle = true;
			int lightToggle = 0;
			nTimeXX = 0;
			while (true)
			{
				if(toggle)
				{
					toggle = !toggle;
					clearScreen();
					displayNextLCDString("Disabled");
				}
				else
				{
					toggle = !toggle;
					clearScreen();
					displayNextLCDString(autonName[currentPosition]);
				}

if(lightToggle < 5)
{
	lightToggle++;
		bLCDBacklight = false;
}
	else
{
lightToggle = 0;
	bLCDBacklight = true;
}
				for (int milliseconds = 0; milliseconds < 1000; milliseconds = milliseconds + 100)
				{
					if (!bIfiRobotDisabled)
						break;

					for (int times = 0; times < 100; times = times + 1)
					{
						if (!bIfiRobotDisabled)
							break;
						displayTime();
						wait1Msec(1);
						if(overrideAll())
						{
							pre_auton();
							nTimeXX = 0;
						}
					}

					if (!bIfiRobotDisabled)
						break;
					++nTimeXX;
				}
				if (!bIfiRobotDisabled)
					break;
			}
			if (!bIfiRobotDisabled)
				break;
		}


		nTimeXX = 0;
		clearScreen();
		if (bIfiAutonomousMode)
		{
			displayNextLCDString("Autonomous");
			StartTask(autonomous);

			// Waiting for autonomous phase to end
			while (bIfiAutonomousMode && !bIfiRobotDisabled)
			{
				if (!bVEXNETActive)
				{
					if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
						allMotorsOff();
				}
				wait1Msec(50);               // Waiting for autonomous phase to end
			}
			allMotorsOff();
			allTasksStop();
		}

		else
		{
			displayNextLCDString("User Control");
			StartTask(usercontrol);

			// Here we repeat loop waiting for user control to end and (optionally) start
			// of a new competition run
			while (!bIfiAutonomousMode && !bIfiRobotDisabled)
			{
				if (nVexRCReceiveState == vrNoXmiters) // the transmitters are powered off!!
					allMotorsOff();
				wait1Msec(100);
			}
			allMotorsOff();
			allTasksStop();
		}
	}
}


void allMotorsOff()
{
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
	motor[port9] = 0;
	motor[port10] = 0;
}

void allTasksStop()
{
	StopTask(1);
	StopTask(2);
	StopTask(3);
	StopTask(4);
	StopTask(5);
	StopTask(6);
	StopTask(7);
	StopTask(8);
	StopTask(9);
	StopTask(10);
	StopTask(11);
	StopTask(12);
	StopTask(13);
	StopTask(14);
	StopTask(15);
	StopTask(16);
	StopTask(17);
	StopTask(18);
	StopTask(19);
}

static void displayTime()
{
	displayLCDPos(1, 0);
	displayNextLCDNumber(nTimeXX / 600, 2);
	displayNextLCDChar(':');
	displayNextLCDNumber((nTimeXX / 10) % 60, -2);
	displayNextLCDChar('.');
	displayNextLCDNumber(nTimeXX % 10, 1);
}

void clearScreen()
{
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDPos(0, 0);
}

bool overrideAll()
{
	if((vexRT[Btn6UXmtr2] == 1 && vexRT[Btn6DXmtr2] == 1) || (vexRT[Btn6U] == 1 && vexRT[Btn6D] == 1) || SensorValue[override])
		return(true);
else
	return(false);
}
