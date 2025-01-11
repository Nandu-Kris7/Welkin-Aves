const int senderPin = 7; // Digital pin 7 as output

void setup() {
  pinMode(senderPin, OUTPUT);
}

void loop() {
  digitalWrite(senderPin, HIGH); // Send HIGH signal
  delayVVV Wait for 1 second
  digitalWrite(senderPin, LOW); // Send LOW signal
  delay(1000); // Wait for 1 second
}
