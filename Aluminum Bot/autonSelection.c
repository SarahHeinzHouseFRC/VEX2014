const int cursorPosition[3][5] = {
	{1,0,1,0,1},						// Line the cursor goes on
	{5,5,7,9,9},						// Position of cursor
	{232,232,229,231,231}}; // Char to display (not functional yet)


void waitForRelease()
{
	while(nLCDButtons != 0){
	//	if(overrideAll())
//			break;
	}
}


void waitForPress()
{
	while(nLCDButtons == 0 && !overrideAll()){
}
}


void moveCursor()
{
	int i = 0;
	while (i <= numberOfAutonPositions)
	{
		if(currentPosition == i)
		{
			setLCDPosition(cursorPosition[0][i], cursorPosition[1][i]);
			//displayNextLCDChar(42); // Display '*'
			displayNextLCDChar(cursorPosition[2][i]); // Display char pointing to selection(not finished)
		}
		else
		{
			setLCDPosition(cursorPosition[0][i], cursorPosition[1][i]);
			displayNextLCDChar(32); // Clear space
		}
		i++;
	}
}





void selectAuton()
{
	bLCDBacklight = true;
		displayBatteryVoltage();
	bool unfinalized;

	waitForPress();				// Display bat stat untill a button is pushed


	unfinalized = true; // Say the selection has not been finalized and can change
	waitForRelease();
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDString(0, 1, "RED1 	X  BLUE1"); // Dislpay a template on the screen for selection
	displayLCDString(1, 1, "RED2     BLUE2");

	while(unfinalized && !overrideAll())
	{
		if(overrideAll())
			break;
		waitForRelease();
		moveCursor();			// Refresh screen after button is released
		waitForPress();		// Wait untill a button is pushed to continue

		if(nLCDButtons == leftButton)
		{
			waitForRelease();
			if(currentPosition == 0)
				currentPosition = numberOfAutonPositions;
			else
				currentPosition--;
		}
		else if(nLCDButtons == rightButton)
		{
			waitForRelease();
			if(currentPosition == numberOfAutonPositions)
				currentPosition = 0;
			else
				currentPosition++;
		}
		else if(nLCDButtons == centerButton)
			unfinalized = false;

		//writeDebugStream(sFormatString, autonName[currentPosition] );  (not working yet)
	}
	waitForRelease();
	selectedAuton = currentPosition;
	clearLCDLine(0);				 // When finalized Display auton name and bat volt
	displayLCDString(0, 1, autonName[currentPosition]);
	sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
	clearLCDLine(1);
	displayLCDString(1, 0, "Battery: ");
	displayNextLCDString(mainBattery);
	wait1Msec(500);
	bLCDBacklight = false;

}
