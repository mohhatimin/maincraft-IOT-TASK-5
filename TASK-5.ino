// Blynk Template & Authentication Setup
#define BLYNK_TEMPLATE_ID "TMPL6FldGk7UQ"
#define BLYNK_TEMPLATE_NAME "ESP32 Control"
#define BLYNK_AUTH_TOKEN "DWKF-sA-jwQv803Tv0OlBCKU7yKV-zym"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// WiFi Configuration for Wokwi Simulator
char ssid[] = "Wokwi-GUEST"; 
char pass[] = "";            

const int ledPin = 2; // Output pin for LED

// Virtual Pin V0 handler for cloud control signals
BLYNK_WRITE(V0) {
  int switchState = param.asInt(); // Reads 1 (ON) or 0 (OFF) from Blynk V0
  digitalWrite(ledPin, switchState); // Sets GPIO 2 output HIGH or LOW
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  
  // Establish WiFi & Blynk Cloud Connection
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run(); // Maintains active communication with Blynk server
}