int ledPins[] = {12, 11, 10, 9, 8}; 
int numLeds = 5;                     

void setup() {
  // Set all pins as OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Turn ON LEDs one by one
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
  }

  // Turn OFF LEDs one by one
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(1000);
  }
}
