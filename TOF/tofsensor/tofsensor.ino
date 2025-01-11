
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();
}

void loop()
{
  int distance =sensor.readRangeContinuousMillimeters();
 distance = distance -30;// -55 is to compensate for error. Change or set it to zero to make it work for your sensor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("mm");
  if (distance<600){
    Serial.println("Trigger action!"); 
  }

}
 