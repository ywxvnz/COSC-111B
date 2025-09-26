int ledPins[] = {12, 11, 10, 9, 8};
int numLeds = 5;
int potPin = A0; 

void setup() {
  int i = 0;
  while (i < numLeds) {
    pinMode(ledPins[i], OUTPUT);
    i++;
  }
}

void loop() {
  int potValue = analogRead(potPin);         
  int mappedValue = map(potValue, 0, 1023, 0, 255);  

  // Turn LEDs ON one by one
  int i = 0;
  while (i < numLeds) {
    int brightness = 0;
    while (brightness <= mappedValue) {
      analogWrite(ledPins[i], brightness);
      delay(1); 
      brightness++;
    }
    delay(1000);  
    i++;
  }

  // Turn LEDs OFF one by one 
  i = 0;
  while (i < numLeds) {
    int brightness = mappedValue;
    while (brightness >= 0) {
      analogWrite(ledPins[i], brightness);
      delay(1);
      brightness--;
    }
    delay(1000);
    i++;
  }
}
