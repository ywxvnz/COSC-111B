// LED Pins
const int redLED = 7;
const int greenLED = 6;
const int blueLED = 5;

// Button Pins
const int btnRed = 12;
const int btnGreen = 11;
const int btnBlue = 10;

// Button state tracking (for single press detection)
bool lastRedBtn = HIGH;
bool lastGreenBtn = HIGH;
bool lastBlueBtn = HIGH;

// LED states for toggling
bool redState = false;
bool greenState = false;
bool blueState = false;

void setup() {
  Serial.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  pinMode(btnRed, INPUT_PULLUP);
  pinMode(btnGreen, INPUT_PULLUP);
  pinMode(btnBlue, INPUT_PULLUP);

  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);
}

void loop() {
  handleButtons();
  handleSerial();
}

// BUTTON → SERIAL (Outbound)
void handleButtons() {
  bool currentRed = digitalRead(btnRed);
  bool currentGreen = digitalRead(btnGreen);
  bool currentBlue = digitalRead(btnBlue);

  // Button 1 → Send 'R'
  if (lastRedBtn == HIGH && currentRed == LOW) {
    Serial.println('R');
    delay(50); // debounce
  }

  // Button 2 → Send 'G'
  if (lastGreenBtn == HIGH && currentGreen == LOW) {
    Serial.println('G');
    delay(50);
  }

  // Button 3 → Send 'B'
  if (lastBlueBtn == HIGH && currentBlue == LOW) {
    Serial.println('B');
    delay(50);
  }

  lastRedBtn = currentRed;
  lastGreenBtn = currentGreen;
  lastBlueBtn = currentBlue;
}

// SERIAL → LED (Inbound) 
void handleSerial() {
  if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case '1':
        redState = !redState;
        digitalWrite(redLED, redState);
        break;

      case '2':
        greenState = !greenState;
        digitalWrite(greenLED, greenState);
        break;

      case '3':
        blueState = !blueState;
        digitalWrite(blueLED, blueState);
        break;
    }
  }
}
