#include <AccelStepper.h>
#include <Servo.h>

#define DIR_PIN 9
#define STEP_PIN 8
#define LIMIT_SWITCH_1 2
#define LIMIT_SWITCH_2 3
const int servo1HomePosition = 60; 
const int servo2HomePosition = 60; 
const int servo3HomePosition = 0; 
bool firstLoop = true;
Servo servo1;
Servo servo2;
Servo servo3;

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  stepper.setMaxSpeed(2000.0);   
  stepper.setAcceleration(10000.0); 
  servo1.attach(6);    
  servo2.attach(10);
  servo3.attach(7);
 
  pinMode(LIMIT_SWITCH_1, INPUT_PULLUP);
  pinMode(LIMIT_SWITCH_2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
   if (firstLoop){
        doThisOnce();
        firstLoop = false;
    }
}

void reset() {
  servo1.write(servo1HomePosition);     
  servo2.write(servo2HomePosition); 
  servo3.write(servo3HomePosition); 
  delay(1000);
  stepper.moveTo(-72000); 
  while (stepper.distanceToGo() != 0 && digitalRead(LIMIT_SWITCH_2) == HIGH && digitalRead(LIMIT_SWITCH_1) == HIGH) {
      stepper.run();
    }

  if (digitalRead(LIMIT_SWITCH_2) == LOW && stepper.distanceToGo() < 0) {
    stepper.setCurrentPosition(0);
    stepper.move(35000);
    while (stepper.distanceToGo() != 0 && digitalRead(LIMIT_SWITCH_1) == HIGH) {
      stepper.run(); 
    }
  }
  servo1.write(0);
  servo2.write(0);
}

void work() {
  stepper.moveTo(72000); 
  while (stepper.distanceToGo() != 0 && digitalRead(LIMIT_SWITCH_2) == HIGH && digitalRead(LIMIT_SWITCH_1) == HIGH) {
      stepper.run();
    }
   if (digitalRead(LIMIT_SWITCH_1) == LOW && stepper.distanceToGo() > 0) {
    stepper.stop();
    delay(1000);
    servo1.write(servo1HomePosition);     
    servo2.write(servo2HomePosition);
    servo3.write(90); 
    delay(1000);
    stepper.setCurrentPosition(0);
    stepper.move(-72000); 
    while (stepper.distanceToGo() != 0 && digitalRead(LIMIT_SWITCH_2) == HIGH) {
      stepper.run();
    }
  }

  if (digitalRead(LIMIT_SWITCH_2) == LOW && stepper.distanceToGo() < 0) {
    stepper.stop();
    delay(1000);
    servo1.write(0);
    servo2.write(0);
    delay(1000);
    stepper.setCurrentPosition(0);
    stepper.move(35000);
    while (stepper.distanceToGo() != 0 && digitalRead(LIMIT_SWITCH_1) == LOW) {
      stepper.run(); 
    }
  }
}

void doThisOnce()
{ 
    reset();
    delay(45000);
    work();
}