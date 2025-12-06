#ifndef LEDFUNCTIONS_H
#define LEDFUNCTIONS_H

#include <Arduino.h>

const int RED_PIN   = 8;
const int GREEN_PIN = 9;
const int YELLOW_PIN  = 10;

extern bool redState;
extern bool greenState;
extern bool yellowState;

void initLeds() {
  pinMode(RED_PIN,   OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN,  OUTPUT);
}

void applyStates() {
  digitalWrite(RED_PIN,   redState   ? HIGH : LOW);
  digitalWrite(GREEN_PIN, greenState ? HIGH : LOW);
  digitalWrite(YELLOW_PIN,  yellowState  ? HIGH : LOW);
}

void toggleRed() {
  redState = !redState; 
  applyStates();  
}

void toggleGreen() {
  greenState = !greenState;
  applyStates();
}

void toggleYellow() {
  yellowState = !yellowState;
  applyStates();
}

void allOn() {
  redState = greenState = yellowState = true;
  applyStates();
}

void allOff() {
  redState = greenState = yellowState = false;
  applyStates();
}

#endif
