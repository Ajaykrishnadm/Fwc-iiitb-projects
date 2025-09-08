#include <Arduino.h>

const int X = 2;
const int Y = 3;
const int Z = 4;

const int D_pin   = 5;  
const int CLK_pin = 6;  
const int Q_pin   = 7;  

int F;

void setup() {
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(Z, INPUT);

  pinMode(D_pin, OUTPUT);
  pinMode(CLK_pin, OUTPUT);
  pinMode(Q_pin, INPUT);   

  Serial.begin(9600);
}

void loop() {
  int x = digitalRead(X);
  int y = digitalRead(Y);
  int z = digitalRead(Z);

  F = ((!x) && y) || (y && z);

  digitalWrite(D_pin, F);

  digitalWrite(CLK_pin, LOW);
  delayMicroseconds(10);
  digitalWrite(CLK_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(CLK_pin, LOW);

  int Q = digitalRead(Q_pin);

  Serial.print("X="); Serial.print(x);
  Serial.print(" Y="); Serial.print(y);
  Serial.print(" Z="); Serial.print(z);
  Serial.print(" => F="); Serial.print(F);
  Serial.print(" | Latched Q="); Serial.println(Q);

  delay(500);
}
