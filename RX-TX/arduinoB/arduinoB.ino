const int receiverPin = A0; // Analog pin A0 as input

void setup() {
  pinMode(receiverPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(receiverPin);
  Serial.print("Received digital signal: ");
  Serial.println(sensorValue);
  delay(1000); // Wait for 1 second
}
