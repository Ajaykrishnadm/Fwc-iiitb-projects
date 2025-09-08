#include <Arduino.h>

const int X=2,Y=3,Z=4;
const int A=5,B=6,C=7,D=8;
int F;

void setup(){
  pinMode(X,INPUT);pinMode(Y,INPUT);pinMode(Z,INPUT);
  pinMode(A,OUTPUT);pinMode(B,OUTPUT);pinMode(C,OUTPUT);pinMode(D,OUTPUT);
}

void loop(){
  int x=digitalRead(X),y=digitalRead(Y),z=digitalRead(Z);
  F=((!x)&&y)||(y&&z);
  if(F==0){
    digitalWrite(A,LOW);digitalWrite(B,LOW);digitalWrite(C,LOW);digitalWrite(D,LOW);
  }else{
    digitalWrite(A,HIGH);digitalWrite(B,LOW);digitalWrite(C,LOW);digitalWrite(D,LOW);
  }
  delay(200);
}
