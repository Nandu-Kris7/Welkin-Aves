const int ledPin = 13;
const int receivePin = A3;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(receivePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  float val = analogRead(3);
  if (val > 0) {
      digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(1000);                      // wait for a second
      digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
      delay(1000);
    }
  }

