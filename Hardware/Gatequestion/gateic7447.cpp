#include <Arduino.h>

// Define input variables (X, Y, Z)
const int X = 2;   // Example input pin for X
const int Y = 3;   // Example input pin for Y
const int Z = 4;   // Example input pin for Z

// 7447 BCD inputs (A=LSB, D=MSB)
const int A = 5;
const int B = 6;
const int C = 7;
const int D = 8;

int F;  // Function output

void setup() {
  // Set input pins
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  pinMode(Z, INPUT);

  // Set 7447 output pins
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  // Start serial monitor
  Serial.begin(9600);
}

void loop() {
  // Read inputs
  int x = digitalRead(X);
  int y = digitalRead(Y);
  int z = digitalRead(Z);

  // Boolean function: F = X'Y + YZ
  F = ((!x) && y) || (y && z);

  // Send function output to 7447 (as BCD code)
  // Here, we’ll display F as "0" or "1" on 7-seg
  if (F == 0) {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW); // BCD for 0
  } else {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW); // BCD for 1
  }

  // Debug
  Serial.print("X="); Serial.print(x);
  Serial.print(" Y="); Serial.print(y);
  Serial.print(" Z="); Serial.print(z);
  Serial.print(" => F="); Serial.println(F);

  delay(500);
}
