#include <AccelStepper.h>

#define STEP_PIN          2
#define DIR_PIN           5
#define STEP_PINy         3
#define DIR_PINy          6
#define STEP_PINz         4
#define DIR_PINz          7

const byte xLimitPin = 10;
const byte yLimitPin = 9;
bool firstLoop = true;

AccelStepper stepperx(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);
AccelStepper steppery(AccelStepper::DRIVER, STEP_PINy, DIR_PINy);
AccelStepper stepperz(AccelStepper::DRIVER, STEP_PINz, DIR_PINz);

void setup() {
  Serial.begin(115200);
  pinMode(xLimitPin, INPUT_PULLUP);
  pinMode(yLimitPin, INPUT_PULLUP);
  
  stepperx.setMaxSpeed(200);  
  stepperx.setSpeed(800);
  stepperx.setAcceleration(50);
  
  steppery.setMaxSpeed(200);  
  steppery.setSpeed(800); 
  steppery.setAcceleration(50);
  
  stepperz.setMaxSpeed(200);  
  stepperz.setSpeed(800);
  stepperz.setAcceleration(50);
}

void reset() {
  stepperx.moveTo(-10000);
  steppery.moveTo(-10000);
  stepperz.moveTo(-10000);

  while (digitalRead(xLimitPin) == HIGH && digitalRead(yLimitPin) == HIGH) {
    stepperx.run();
    steppery.run();
    stepperz.run();
  }

  if (digitalRead(xLimitPin) == LOW) {
    stepperx.stop();
    steppery.stop();
    stepperz.stop();
  }

  stepperx.setCurrentPosition(0);
  steppery.setCurrentPosition(0);
  stepperz.setCurrentPosition(0);
}

void work() {
  stepperx.moveTo(10000);
  steppery.moveTo(10000);
  stepperz.moveTo(10000);

  while (digitalRead(yLimitPin) == HIGH) {
    stepperx.run();
    steppery.run();
    stepperz.run();
  }

  if (digitalRead(yLimitPin) == LOW) {
    stepperx.stop();
    steppery.stop();
    stepperz.stop();
  }

  stepperx.setCurrentPosition(0);
  steppery.setCurrentPosition(0);
  stepperz.setCurrentPosition(0);
  
}
void work1() {
  stepperx.moveTo(-10000);
  steppery.moveTo(-10000);
  stepperz.moveTo(-10000);

  while (digitalRead(xLimitPin) == HIGH) {
    stepperx.run();
    steppery.run();
    stepperz.run();
  }

  if (digitalRead(xLimitPin) == LOW) {
    stepperx.stop();
    steppery.stop();
    stepperz.stop();
  }
  delay(30000);
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
  delay(50000);
  work();
  delay(120000);
  work1();
 
}