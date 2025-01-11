
const int ledPin = 13;
const int sendPin = 12;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(sendPin, HIGH);
}

void loop() {
digitalWrite(ledPin, HIGH);
delay(1000);
  
}
