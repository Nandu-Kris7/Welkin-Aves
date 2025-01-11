#include <Stepper.h>

const int stepsPerRevolution = 200; // Change this according to your stepper motor
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // Adjust pins based on your setup

const int limitSwitch2 = 2;
const int transmitPin = 3;
const int receivePin = 4;

void setup() {
  pinMode(limitSwitch2, INPUT);
  pinMode(transmitPin, OUTPUT);
  pinMode(receivePin, INPUT);
  Serial.begin(9600);
  myStepper.setSpeed(100); // Set the speed of the stepper motor
}

void loop() {
  if (digitalRead(limitSwitch2) == HIGH) {
    Serial.println("Actuator2Limit");
    while (Serial.available() <= 0);
    if (Serial.readString() == "MoveActuator1") {
      Serial.println("Actuator2Move");
      // Move Actuator 2 to opposite direction
      myStepper.step(-stepsPerRevolution); // Example: Move one full revolution in opposite direction
    }
  }
}
