#include "LedFunctions.h"  

bool redState   = false;  
bool greenState = false;
bool yellowState  = false;

void setup() {
  initLeds();  
  Serial.begin(9600);  

  Serial.println("Ready. Commands: R, G, Y, A, O");
}

void loop() {
  if (Serial.available() > 0) {  

    char cmd = Serial.read();  

    if (cmd == '\n' || cmd == '\r') {
      Serial.println("here");
      return;  
    }

    if (cmd >= 'a' && cmd <= 'z') {
      cmd = cmd - 'a' + 'A';  
    }

    switch (cmd) {
      case 'R':
        toggleRed();  
        Serial.println("Toggled RED");  
        break;

      case 'G':
        toggleGreen();  
        Serial.println("Toggled GREEN");
        break;

      case 'Y':
        toggleYellow();  
        Serial.println("Toggled YELLOW");
        break;

      case 'A':
        allOn();  
        Serial.println("All LEDs ON");
        break;

      case 'O':
        allOff();  
        Serial.println("All LEDs OFF");
        break;

      default:
        Serial.println("Error: Invalid Command");
    }
  }
}
