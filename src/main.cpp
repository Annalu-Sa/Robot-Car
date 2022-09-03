#include <Arduino.h>
#include <HCSR04.h>

const int TRIGGER_PIN = 4;
const int ECHO_PIN = 5;
const int obstacle_distance = 20;
UltraSonicDistanceSensor distanceSensor (TRIGGER_PIN,ECHO_PIN);
#define IN1 2
#define IN2 7
#define IN3 8 
#define IN4 9

void setup() 
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
   straight();
   int distance = dist(TRIGGER_PIN, ECHO_PIN);
   if(distance <= obstacle_distance)
   {
      Serial.print("Obstacle in: ");
      Serial.print(distance);
      Serial.println("cm");
      Which_way();
    }
    else
    {
      Serial.print("Without obstacle: ");
      Serial.print(distance);
      Serial.println("cm");
      straight();  
    }
    delay(100);
}

int dist(int trigpin, int pinecho)
{
  digitalWrite(trigpin, LOW);
  delayMicroseconds(100);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(200);
  digitalWrite(trigpin, LOW);

  return pulseIn(pinecho, HIGH)/58;
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