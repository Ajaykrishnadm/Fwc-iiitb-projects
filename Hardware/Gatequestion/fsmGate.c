#include <Arduino.h>

const int X=2,Y=3,Z=4,D=5,CLK=6,Q=7;
int F,Qs;

void setup(){
  pinMode(X,INPUT); pinMode(Y,INPUT); pinMode(Z,INPUT);
  pinMode(D,OUTPUT); pinMode(CLK,OUTPUT); pinMode(Q,INPUT);
  Serial.begin(9600);
}

void loop(){
  int x=digitalRead(X),y=digitalRead(Y),z=digitalRead(Z);
  F=((!x)&&y)||(y&&z);
  digitalWrite(D,F);
  digitalWrite(CLK,LOW); delayMicroseconds(5);
  digitalWrite(CLK,HIGH); delayMicroseconds(5);
  digitalWrite(CLK,LOW);
  Qs=digitalRead(Q);
  Serial.print("X=");Serial.print(x);
  Serial.print(" Y=");Serial.print(y);
  Serial.print(" Z=");Serial.print(z);
  Serial.print(" F=");Serial.print(F);
  Serial.print(" Q=");Serial.println(Qs);
  delay(500);
}
