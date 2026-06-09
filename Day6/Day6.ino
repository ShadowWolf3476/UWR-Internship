/*Dynamic Headlight System*/

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

  // Read LDR
  int ldrValue = analogRead(LDR_PIN);

  // Measure distance
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  float distance = duration * 0.0343 / 2;

  int brightness = 0;

  // Only work when dark
  if (ldrValue > 300) {

    // Near object = bright LED
    // Far object = dim LED
    brightness = map(distance, 5, 100, 5, 255);

    // Keep brightness within valid range
    brightness = constrain(brightness, 5, 255);

  } else {
    brightness = 0; // Daytime
  }

  analogWrite(LED_PIN, brightness);

  Serial.print("LDR: ");
  Serial.print(ldrValue);

  Serial.print(" | Distance: ");
  Serial.print(distance);

  Serial.print(" cm | Brightness: ");
  Serial.println(brightness);

  delay(200);
}