#include <Stepper.h>

const int stepsPerRevolution = 200; // Change this according to your stepper motor
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // Adjust pins based on your setup

const int limitSwitch1 = 2;
const int transmitPin = 3;
const int receivePin = 4;

void setup() {
  pinMode(limitSwitch1, INPUT);
  pinMode(transmitPin, OUTPUT);
  pinMode(receivePin, INPUT);
  Serial.begin(9600);
  myStepper.setSpeed(100); // Set the speed of the stepper motor
}

void loop() {
  if (digitalRead(limitSwitch1) == HIGH) {
    Serial.println("Actuator1Limit");
    while (Serial.available() <= 0);
    if (Serial.readString() == "Actuator2Limit") {
      Serial.println("MoveActuator1");
      // Move Actuator 1 to opposite direction
      myStepper.step(-stepsPerRevolution); // Example: Move one full revolution in opposite direction
    }
  }
}
