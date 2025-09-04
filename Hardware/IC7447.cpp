#include <Arduino.h>

const uint8_t PIN_A = 2;
const uint8_t PIN_B = 3;
const uint8_t PIN_C = 4;
const uint8_t PIN_D = 5;

void displayNumber(uint8_t num);

void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
}

void loop() {
  static uint8_t num = 0;

  displayNumber(num);   // show current digit
  delay(1000);          // 1 second

  num++;
  if (num > 9) num = 0; // 7447 only decodes 0–9
}

void displayNumber(uint8_t num) {
  digitalWrite(PIN_A,  num & 0x01);        // bit 0 (LSB)
  digitalWrite(PIN_B, (num >> 1) & 0x01);  // bit 1
  digitalWrite(PIN_C, (num >> 2) & 0x01);  // bit 2
  digitalWrite(PIN_D, (num >> 3) & 0x01);  // bit 3 (MSB)
}
