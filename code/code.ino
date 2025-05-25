#include <Servo.h>

Servo dirServo;

int S0 = 4;
int S1 = 5;
int S2 = 6;
int S3 = 7;
int sensorOut = 8;

int ENA = A0;
int motor = 2;

int red = 0;
int green = 0;
int blue = 0;

int initialPosition = 90;

void setup() {
  dirServo.attach(9);
  dirServo.write(initialPosition);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {

  analogWrite(ENA, 128);
  digitalWrite(motor, HIGH);

  red = readColor(LOW, LOW);
  green = readColor(HIGH, HIGH);
  blue = readColor(LOW, HIGH);

 
  if (red > 150 && green > 80 && blue < 70) {
    dirServo.write(initialPosition + 45);
  } 
  else if (red < 100 && green > 150 && blue > 150) {
    dirServo.write(initialPosition - 45);
  } 
  else {
    dirServo.write(initialPosition);
  }

  delay(1000);
}

int readColor(bool s2, bool s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(50);
  return pulseIn(sensorOut, LOW);
}
