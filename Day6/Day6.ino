/* Dynamic Headlight System
   Prototype that uses an LDR and ultrasonic sensor to control LED brightness. */

#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 3
#define LDR_PIN A0

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  // Read ambient light from the LDR
  int ldrValue = analogRead(LDR_PIN);

  // Trigger the ultrasonic sensor and measure the echo pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // Convert echo time to distance in centimeters
  float distance = duration * 0.0343 / 2;

  int brightness = 0;

  // Only activate the LED when the surroundings are dark enough
  if (ldrValue > 300) {

    // Map closer objects to higher brightness values
    brightness = map(distance, 5, 100, 5, 255);

    // Keep the PWM value within a valid range
    brightness = constrain(brightness, 5, 255);

  } else {
    brightness = 0; // Turn off the LED in brighter conditions
  }

  analogWrite(LED_PIN, brightness);

  // Print values for Serial Monitor debugging
  Serial.print("LDR: ");
  Serial.print(ldrValue);

  Serial.print(" | Distance: ");
  Serial.print(distance);

  Serial.print(" cm | Brightness: ");
  Serial.println(brightness);

  delay(200);
}
