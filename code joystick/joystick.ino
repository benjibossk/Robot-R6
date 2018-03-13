#include <Servo.h>

Servo hori;
Servo verti;

//int joyX = 1;
//int joyY = 0;

int joyValX;
int joyValY;

void setup(){
  hori.attach(10);
  verti.attach(11);
  Serial.begin(9600);
}

void loop(){
  joyValX = analogRead(A1);
  Serial.println(joyValX);
  joyValX = map (joyValX, 0, 1023, 0, 170);
  hori.write(joyValX);
  
  joyValY = analogRead(A0);
  Serial.println(joyValY);
  joyValY = map(joyValY, 0, 1023, 0, 170);
  verti.write(joyValY);
  
  delay(15);
}

