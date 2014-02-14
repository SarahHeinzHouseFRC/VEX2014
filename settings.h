int threshold = 10;      // Threshold for driving deadzone
int intakeSpeed = 80;    // Speed of the intake
int armSpeed = 127;      // Speed of arm for upward movment
int armDownSpeed = 120;  // Speed of arm for downward movement
int slowSpeed = 20;      // Speed of arm for downward movement while near the bottom to prevent the arm from slamming into the ground
int slowdPosition = 800; // Position to start slowing down the arm
int maxHeight = 2400;    // Maximum code allowed pot value number for arm to get to so the pot dosent break.
int scoreHeight = 1900;  // Height of arm that is optimum for scoring
int zeroValue = 450;     // Value of pot at zero arm height
int acceptedError = 5;
int liftDriveTicks = -1000;
int liftExtendedTicks = -5300;
int pistonState = 0;    // 0 is throw, 1 is up, 2 is down
bool mainJoystickActive = true;
string mainBattery, backupBattery;
int selectedAuton = 2; //2 is no auton
int intakeTicks;
int currentPosition = 2;	// No position is default, 0=RED1 1=RED2 2=NONE 3=BLUE1 4=BLUE2
const string autonName[5] = {"RED CORNER", "RED BALLS", "NONE", "BLUE SKILLS", "BLUE BALLS"};
const int leftButton = 1, centerButton = 2, rightButton = 4, numberOfAutonPositions = 4;
int armTarget;
