#include <Arduino.h>

// PC13 is the onboard LED on the Blue Pill (active LOW)
#define LED_PIN PC13

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, LOW);   // LED on
    delay(500);
    digitalWrite(LED_PIN, HIGH);  // LED off
    delay(500);
}
