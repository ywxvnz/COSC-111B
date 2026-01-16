// ===== PIN DEFINITIONS =====
#define RED_LED     7
#define GREEN_LED   6
#define BLUE_LED    5

#define BTN_RED     12
#define BTN_GREEN   11
#define BTN_BLUE    10

// ===== LED STATES =====
bool redState = false;
bool greenState = false;
bool blueState = false;

// ===== BUTTON STATES =====
bool lastBtnRed = HIGH;
bool lastBtnGreen = HIGH;
bool lastBtnBlue = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(BTN_RED, INPUT_PULLUP);
  pinMode(BTN_GREEN, INPUT_PULLUP);
  pinMode(BTN_BLUE, INPUT_PULLUP);

  Serial.println("Arduino Ready");
}

void loop() {
  handleSerialInput();
  handleButtons();
}

// ===== HANDLE SERIAL INPUT (FROM FASTAPI / SERIAL MONITOR) =====
void handleSerialInput() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    switch (cmd) {
      case '1':   // Toggle RED LED
        redState = !redState;
        digitalWrite(RED_LED, redState);
        Serial.println("RED LED TOGGLED");
        break;

      case '2':   // Toggle GREEN LED
        greenState = !greenState;
        digitalWrite(GREEN_LED, greenState);
        Serial.println("GREEN LED TOGGLED");
        break;

      case '3':   // Toggle BLUE LED
        blueState = !blueState;
        digitalWrite(BLUE_LED, blueState);
        Serial.println("BLUE LED TOGGLED");
        break;

      case 'o':   // Turn ALL ON
      case 'O':
        setAllLEDs(true);
        Serial.println("ALL LEDS ON");
        break;

      case 'f':   // Turn ALL OFF
      case 'F':
        setAllLEDs(false);
        Serial.println("ALL LEDS OFF");
        break;
    }
  }
}

// ===== HANDLE BUTTON INPUT (BI-DIRECTIONAL) =====
void handleButtons() {
  bool btnRed = digitalRead(BTN_RED);
  bool btnGreen = digitalRead(BTN_GREEN);
  bool btnBlue = digitalRead(BTN_BLUE);

  if (btnRed == LOW && lastBtnRed == HIGH) {
    redState = !redState;
    digitalWrite(RED_LED, redState);
    Serial.println("BUTTON: RED TOGGLED");
    delay(200);
  }

  if (btnGreen == LOW && lastBtnGreen == HIGH) {
    greenState = !greenState;
    digitalWrite(GREEN_LED, greenState);
    Serial.println("BUTTON: GREEN TOGGLED");
    delay(200);
  }

  if (btnBlue == LOW && lastBtnBlue == HIGH) {
    blueState = !blueState;
    digitalWrite(BLUE_LED, blueState);
    Serial.println("BUTTON: BLUE TOGGLED");
    delay(200);
  }

  lastBtnRed = btnRed;
  lastBtnGreen = btnGreen;
  lastBtnBlue = btnBlue;
}

// ===== HELPER FUNCTION =====
void setAllLEDs(bool state) {
  redState = state;
  greenState = state;
  blueState = state;

  digitalWrite(RED_LED, state);
  digitalWrite(GREEN_LED, state);
  digitalWrite(BLUE_LED, state);
}
