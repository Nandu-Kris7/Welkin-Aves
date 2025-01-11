#include <AccelStepper.h>

#define STEP_PIN          2
#define DIR_PIN           5
#define STEP_PINy         3
#define DIR_PINy          6
#define STEP_PINz         4
#define DIR_PINz          7

const byte xLimitPin = 9;
const byte yLimitPin = 10; 
bool firstLoop = true;
AccelStepper stepperx(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);
AccelStepper steppery(AccelStepper::DRIVER, STEP_PINy, DIR_PINy);
AccelStepper stepperz(AccelStepper::DRIVER, STEP_PINz, DIR_PINz);

void setup() {
  Serial.begin(115200);
  pinMode(xLimitPin, INPUT_PULLUP);
  pinMode(yLimitPin, INPUT_PULLUP);
  
  stepperx.setMaxSpeed(500);  
  stepperx.setSpeed(200); 
  stepperx.setAcceleration(80);
  
  steppery.setMaxSpeed(500);  
  steppery.setSpeed(200);
  steppery.setAcceleration(80);
  
  stepperz.setMaxSpeed(500);  
  stepperz.setSpeed(200); 
  stepperz.setAcceleration(80);
}

void reset() {
  stepperx.move(10000);
  steppery.move(10000);
  stepperz.move(10000);

  while (digitalRead(xLimitPin) == HIGH && digitalRead(yLimitPin) == HIGH) {
    stepperx.run();
    steppery.run();
    stepperz.run();
  }

  if (digitalRead(yLimitPin) == LOW) {
    stepperx.stop();
    steppery.stop();
    stepperz.stop();
    stepperx.setCurrentPosition(0);
    steppery.setCurrentPosition(0);
    stepperz.setCurrentPosition(0);
  }
  delay(8000);
}

void work() {
  stepperx.move(-10000);
  steppery.move(-10000);
  stepperz.move(-10000);

  while (digitalRead(xLimitPin) == HIGH) {
    stepperx.run();
    steppery.run();
    stepperz.run();
  }

  if (digitalRead(xLimitPin) == LOW) {
    stepperx.stop();
    steppery.stop();
    stepperz.stop();
    stepperx.setCurrentPosition(0);
    steppery.setCurrentPosition(0);
    stepperz.setCurrentPosition(0);
  }
  delay(170000);
  stepperx.move(10000);
  steppery.move(10000);
  stepperz.move(10000);

  while (digitalRead(yLimitPin) == HIGH) {
    stepperx.run();
    steppery.run();
    stepperz.run();
  }
  if (digitalRead(yLimitPin) == LOW) {
    stepperx.stop();
    steppery.stop();
    stepperz.stop();
    stepperx.setCurrentPosition(0);
    steppery.setCurrentPosition(0);
    stepperz.setCurrentPosition(0);
  }
}

void loop() {
if (firstLoop){
        doThisOnce();
        firstLoop = false;
    }
}
void doThisOnce()
{ 
  reset();
  delay(1200);
  work();
    
}

