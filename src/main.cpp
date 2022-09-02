#include <Arduino.h>
#include <Ultrassonic.h>

#define TRIGGER_PIN 4
#define ECHO_PIN 5
Ultrassonic ultrassonic(TRIGGER_PIN,ECHO_PIN);
#define IN1 2
#define IN2 7
#define IN3 8 
#define IN4 9

void setup() 
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
}

float dist()
{
  float cmMec;
  long microsec = ultrassonic.timing();
  cmMec = ultrassonic.convert(microsec, Ultrassonic::CM);
  delay(10);
}

void straight()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void Which_way()
{
  stop();
  left();
  delay(400);
  stop();
  delay(500);
}