#define PHOTORESISTOR_PIN A0   
#define LED_PIN 8

const int BRIGHTNESS_THRESHOLD = 220;  // Threshold for light level
bool isBlinking = false;               // Tracks whether LED should blink or not
bool stopCommand = false;              // To stop blinking when "stop" is typed

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Arduino Serial Connection Initialized");
  Serial.println("Type 'stop' to stop the LED blinking.");
}

void loop() {
  int brightness = analogRead(PHOTORESISTOR_PIN);
  brightness = map(brightness, 0, 1023, 0, 250); // Normalize LDR value

  Serial.print("Brightness: ");
  Serial.println(brightness);

  // Check brightness threshold
  if (brightness >= BRIGHTNESS_THRESHOLD && !stopCommand) {
    isBlinking = true; // Start blinking once threshold is met
  }

  // Handle Serial input
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Remove spaces/newlines

    if (command.equalsIgnoreCase("stop")) {
      stopCommand = true;
      isBlinking = false;
      digitalWrite(LED_PIN, LOW);
      Serial.println("Blinking stopped.");
    }
  }

  // LED blinking behavior
  if (isBlinking && !stopCommand) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(500); // Sensor reading delay
}
