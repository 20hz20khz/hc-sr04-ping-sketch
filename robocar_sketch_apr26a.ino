/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v
 GND to arduino GND
 Echo to Arduino pin 13
 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 //560 ohm resistor to both LED NEG and GRD power rail
 More info at: http://goo.gl/kJ8Gl
 Original code improvements to the Ping sketch sourced from Trollmaker.com
 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 */

#include <Servo.h> 

Servo myservo;
Servo myservo2;

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10
//#define MotorA1 9
//#define MotorA2 8


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  //pinMode(MotorA1, OUTPUT); 
  //pinMode(MotorA2, OUTPUT); 
  myservo.attach(9);
  myservo.write(90);  // set servo to mid-point
  myservo2.attach(8);
  myservo2.write(90);  // set servo to mid-point
}

void goBot(){ 
   //digitalWrite (MotorA1, HIGH);                              
   //digitalWrite (MotorA2, HIGH); 
   myservo.write(180);  // set servo to 180
   myservo2.write(1);  // set servo to mid-point
}

void stopBot(){ 
   //digitalWrite (MotorA1, LOW);                              
   //digitalWrite (MotorA2, LOW); 
   myservo.write(90);  // set servo to mid-point
   myservo2.write(90);  // set servo to mid-point
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if ( distance <= 0){
    distance =999;
  }
  if (distance < 50) {  // This is where the LED On/Off happens, < 50cm
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(led2,LOW);
    goBot();
  }
  else {
    stopBot();
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
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
