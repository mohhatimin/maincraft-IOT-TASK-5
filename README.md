# 🚀 IoT Automation with Cloud Control & Mobile App Integration (Task 5)

[![Embedded Systems](https://img.shields.io/badge/Domain-Embedded%20Systems%20%26%20IoT-blue)](https://github.com)
[![Platform](https://img.shields.io/badge/Platform-Blynk%20Cloud-orange)](https://blynk.cloud)
[![Simulator](https://img.shields.io/badge/Simulator-Wokwi-green)](https://wokwi.com)

This repository contains the complete implementation, documentation, and source code for **Task 5** of the Embedded Systems & IoT internship. The project upgrades a one-way sensor monitoring system into a **bi-directional cloud-controlled IoT system**.

---

## 📋 Table of Contents
- [Project Overview](#-project-overview)
- [System Architecture & Signal Flow](#-system-architecture--signal-flow)
- [Components & Tools](#-components--tools)
- [Circuit Connections](#-circuit-connections)
- [Source Code](#-source-code)
- [Dashboard Setup](#-dashboard-setup)
- [Verification & System Output](#-verification--system-output)
- [Key Learning Outcomes](#-key-learning-outcomes)

---

## 🔍 Project Overview
Unlike standard monitoring setups (which only push sensor data to the cloud), this system enables **real-time remote actuation**. By toggling a switch on a mobile app or web dashboard, users can control physical or simulated hardware components instantly across the internet.

---

## ⚡ System Architecture & Signal Flow
The remote automation mechanism operates via a 5-step bi-directional loop:
1. **User Action:** User toggles the virtual switch on the Blynk Web/Mobile Dashboard.
2. **Cloud Transmission:** Blynk Cloud Server receives the state command (`1` for ON, `0` for OFF).
3. **ESP32 Polling:** The ESP32 constantly maintains communication with the server using `Blynk.run()`.
4. **Firmware Trigger:** State changes trigger the `BLYNK_WRITE(V0)` event handler function.
5. **Hardware Execution:** The ESP32 applies a HIGH or LOW digital signal to **GPIO Pin 2**, controlling the LED/Relay state in real time.

---

## 🛠️ Components & Tools
* **Microcontroller:** ESP32 Development Board
* **Simulator:** Wokwi Online ESP32 Simulator
* **Cloud Platform:** Blynk IoT Console (`blynk.cloud`)
* **IDE:** Arduino IDE / Wokwi Web Editor
* **Peripherals:** Standard LED & $220\:\Omega$ Resistor

---

## 🔌 Circuit Connections
| Component Pin | ESP32 Pin / Rail | Description |
| :--- | :--- | :--- |
| **LED Anode (+ / Bent Leg)** | **GPIO 2** | Digital output signal pin |
| **LED Cathode (- / Straight Leg)** | **Resistor ($220\:\Omega$)** | Current-limiting protection |
| **Resistor (Other End)** | **GND** | Ground reference |

---

## 💻 Source Code
```cpp
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
```

---

## 📊 Dashboard Setup
* **Platform:** Blynk IoT Console (`blynk.cloud`)
* **Datastream Configured:** `Virtual Pin V0` (Integer, Min: 0, Max: 1)
* **Widget:** Switch Widget mapped to `V0`

---

## 🔍 Verification & System Output
* **Simulation Status:** Verified successfully on the Wokwi ESP32 Simulator.
* **Real-time Performance:** Toggling the switch on the Blynk web console turns the simulated LED ON and OFF instantly.

---

## 🎯 Key Learning Outcomes
* Implemented bi-directional IoT communication using Virtual Pins in Blynk.
* Integrated cloud-based remote control with embedded hardware peripherals.
* Configured and verified simulation workflows using Wokwi and Blynk cloud APIs.
