#define triggerPin 13
#define echoPin 12
#define redLED 11
#define greenLED 10

void setup() {
  Serial.begin (9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the redLED On/Off happens
    digitalWrite(redLED,HIGH); // When the Red condition is met, the Green redLED should turn off
    digitalWrite(greenLED,LOW);
  }
  else {
    digitalWrite(redLED,LOW); // When the Red is off, the Green redLED is on
    digitalWrite(greenLED,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
