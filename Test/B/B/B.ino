const int ledPin = 13;
const int receivePin = A3;
const int sendPin = 5;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(receivePin, INPUT);
  pinMode(sendPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float val = analogRead(3);
  if (val > 0) {
      digitalWrite(ledPin, HIGH);
      digitalWrite(sendPin, HIGH);
      delay(100000); 
      
    }
  }

