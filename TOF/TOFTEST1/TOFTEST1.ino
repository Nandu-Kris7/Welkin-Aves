
#include <AccelStepper.h>

// Define the stepper motor connections and create instances
AccelStepper stepperX(AccelStepper::DRIVER, 2, 5); // Step and Dir pins for X-axis
AccelStepper stepperY(AccelStepper::DRIVER, 3, 6); // Step and Dir pins for Y-axis
AccelStepper stepperZ(AccelStepper::DRIVER, 4, 7); // Step and Dir pins for Z-axis
AccelStepper stepperA(AccelStepper::DRIVER, 8, 9); // Step and Dir pins for A-axis

void setup() {
  // Set up your stepper motor configurations here (e.g., max speed, acceleration)
  stepperX.setMaxSpeed(1000); // Set your desired max speed in steps per second
  stepperX.setAcceleration(500); // Set your desired acceleration in steps per second^2

  stepperY.setMaxSpeed(1000);
  stepperY.setAcceleration(500);

  stepperZ.setMaxSpeed(1000);
  stepperZ.setAcceleration(500);

  stepperA.setMaxSpeed(1000);
  stepperA.setAcceleration(500);
}

void loop() {
  // Use the stepper motor instances to control the motors as needed
  stepperX.moveTo(1000); // Set your desired position in steps
  stepperX.runToPosition();

  stepperY.moveTo(2000);
  stepperY.runToPosition();

  stepperZ.moveTo(3000);
  stepperZ.runToPosition();

  stepperA.moveTo(4000);
  stepperA.runToPosition();
}