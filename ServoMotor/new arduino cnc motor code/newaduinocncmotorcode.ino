#include <AccelStepper.h>
#define STEP_PIN          2
#define DIR_PIN           5
const byte xLimitPin = 9;
const byte yLimitPin = 10;
const byte zLimitPin = 11;

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);
bool forwardLimitSwitchTriggered = false;
bool backwardLimitSwitchTriggered = false;

void setup()
{
  Serial.begin(115200);
  pinMode(xLimitPin, INPUT_PULLUP);
  pinMode(yLimitPin, INPUT_PULLUP);
  pinMode(zLimitPin, INPUT_PULLUP);
  stepper.setMaxSpeed(1000);  
  stepper.setSpeed(800);// Set your desired max speed in steps per second here
  stepper.setAcceleration(5000);
}

void MoveFrwd(int xLimitPin){
  if (digitalRead(xLimitPin) == LOW) 
  {
    stepper.setCurrentPosition(0);
    forwardLimitSwitchTriggered = true;
    delay(1000);  
    stepper.moveTo(10000);
    StopFunc();
  }
}

void MoveBcwd(int yLimitPin){
  if (digitalRead(yLimitPin) == LOW) 
  {
    stepper.setCurrentPosition(0);
    backwardLimitSwitchTriggered = true;
    delay(1000);  
    stepper.moveTo(-10000);
  }
}

void StopFunc(){
 stepper.stop();
  }

void loop(){
stepper.moveTo(10000);
while(true){
  
  MoveFrwd(xLimitPin);
  MoveBcwd(yLimitPin);
  stepper.run();}
}

  