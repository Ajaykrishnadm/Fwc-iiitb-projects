#include<Arduino.h>
const int pinX = 6;
const int pinY = 7;
const int pinZ = 8;
const int bcdPins[4] = {2, 3, 4, 5};

void setup() {
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(pinZ, INPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(bcdPins[i], OUTPUT);
  }
}

void loop() {
  int X = digitalRead(pinX);
  int Y = digitalRead(pinY);
  int Z = digitalRead(pinZ);
  int F = (!X) || (Y && Z);
  digitalWrite(bcdPins[0], F);
  digitalWrite(bcdPins[1], LOW);
  digitalWrite(bcdPins[2], LOW);
  digitalWrite(bcdPins[3], LOW);
  delay(200);
}
