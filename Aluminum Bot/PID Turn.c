float pidError, pidLastError, pidDerivative, pidDrive;
long pidIntegral;
float pid_Kp = 0.35;
float pid_Ki = 0.00001;
float pid_Kd = 0.1;
int slowest = 30;



void pointTurnPID(int target)
{
for(int times = 0;times<2;times++)
	{
		while(SensorValue[gyro] > target + acceptedError || SensorValue[gyro] < target - acceptedError)
		{
     	pidError = SensorValue[gyro] - target; // Find Error

			if(pid_Ki != 0 )  // Find I
			{
				if( abs(pidError) < 20 )
					pidIntegral = pidIntegral + pidError;
				else
					pidIntegral = 0;
			}
			else
				pidIntegral = 0;

			if( pid_Kd != 0 )
			{
				pidDerivative = pidError - pidLastError; // Find Derivative
				pidLastError  = pidError;
			}
			else
				pidLastError  = 0;

			pidDrive = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative); // find motor speed

			if( pidDrive > 127 )// limit drive
				pidDrive = 127;
			else if( pidDrive < -127 )
				pidDrive = -127;
			else if( pidDrive < slowest && pidDrive > -slowest )
			 if( pidDrive > 0 )
				pidDrive = slowest;
	  	else if( pidDrive < 0 )
				pidDrive = -slowest;

			driveAtSpeed(-pidDrive, pidDrive); // update drive


	}
		driveAtSpeed(0, 0);
		wait10Msec(5);
}
	driveAtSpeed(0, 0);
	pidError      = 0;
	pidLastError  = 0;
	pidIntegral   = 0;
	pidDerivative = 0;
}
