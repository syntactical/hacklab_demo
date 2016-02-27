#include <NewPing.h>

#define TRIGGER_PIN  3
#define ECHO_PIN     2
#define LED_PIN 6
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  delay(50);
  int uS = sonar.ping();
  
  int distance = uS / US_ROUNDTRIP_CM;
  
  Serial.println(distance);

  if (distance < 20 && distance != 0) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
