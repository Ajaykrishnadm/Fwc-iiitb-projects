#include <Arduino.h>

// Arduino pins to 7447 inputs
const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop() {
  for (int num = 0; num < 16; num++) {   // Full 4-bit range
    displayNumber(num);
    delay(1000);
  }
}

void displayNumber(int num) {
  if (num >= 0 && num <= 9) {
    // Valid BCD → Send to 7447
    digitalWrite(A, num & 0x01);
    digitalWrite(B, (num >> 1) & 0x01);
    digitalWrite(C, (num >> 2) & 0x01);
    digitalWrite(D, (num >> 3) & 0x01);
  } 
  else {
    // Invalid BCD (10–15) → Don't care → Blank
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
  }
}
