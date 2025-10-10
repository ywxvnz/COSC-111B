// Pin definitions
#define THERMISTOR_PIN A0
#define PHOTORESISTOR_PIN A2
#define LED_BUZZER_PIN 12  // LED + Buzzer 

// Thresholds
const int TEMP_THRESHOLD = 50;        // Celsius
const int BRIGHTNESS_THRESHOLD = 220; // Light level

// Thermistor constants
const float beta = 3950.0;        // Beta value
const float resistance = 10000.0; // 10k ohm at 25 °C

// Function to read temperature in Celsius
float readTemperature() {
  int analogValue = analogRead(THERMISTOR_PIN);
  float tempC = beta / (log(1025.0 * resistance / analogValue - resistance) / resistance + beta / 298.0) - 273.0;
  return tempC;
}

// Function to read brightness
int readBrightness() {
  return analogRead(PHOTORESISTOR_PIN);
}

void setup() {
  pinMode(LED_BUZZER_PIN, OUTPUT); // One pin for both LED and Buzzer
}

void loop() {
  float tempC = readTemperature();
  int brightness = readBrightness();

  if (tempC >= TEMP_THRESHOLD && brightness >= BRIGHTNESS_THRESHOLD) {
    digitalWrite(LED_BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(LED_BUZZER_PIN, LOW);
    delay(200);
  } else {
    digitalWrite(LED_BUZZER_PIN, LOW);
  }
}