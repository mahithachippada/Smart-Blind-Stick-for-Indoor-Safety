# Smart Blind Stick using ESP32 with Bluetooth and Panic Alert

##  Project Overview
This project presents an IoT-based Smart Blind Stick designed to assist visually impaired individuals.
The system uses an ESP32 microcontroller to detect obstacles, water presence, and emergency situations.
Alerts are provided through a buzzer and Bluetooth notifications to a paired smartphone.

---

##  Features
- Ultrasonic obstacle detection
- Water detection for safety
- Emergency panic button
- Bluetooth communication with smartphone
- Audio alerts using buzzer
- Portable, low-cost, and energy-efficient design

---

##  Hardware Components
- ESP32 Development Board
- Ultrasonic Sensor (HC-SR04)
- Water Sensor
- Buzzer
- Push Button (Panic Button)
- Jumper Wires
- Power Supply / Battery

---

##  Software & Tools
- Arduino IDE
- ESP32 Board Package
- BluetoothSerial Library
- Online Circuit Designing Tool

---

##  System Working
1. The ultrasonic sensor continuously measures the distance to detect obstacles.
2. When an obstacle is detected within 25 cm, the buzzer alerts the user.
3. The water sensor detects wet surfaces and warns the user to avoid unsafe paths.
4. The panic button allows the user to send an emergency alert instantly.
5. Bluetooth sends real-time alert messages to a connected smartphone.

---

##  Code Explanation
- The ultrasonic sensor calculates distance using `pulseIn()` method.
- The water sensor determines dry or wet surface conditions.
- The panic button triggers an emergency alert with continuous buzzer sound.
- BluetoothSerial library sends alert messages to the mobile device.
- The buzzer provides immediate audio feedback for all alerts.

---

##  Online Circuit Design
Online simulation and circuit design link:  
- [https://wokwi.com/projects/441887797091348481]
- [https://app.cirkitdesigner.com/project/db48362d-9093-4887-bf27-7d6436987222]

---


##  Patent Information
This project has been filed for patent protection.

**Patent Title:** Smart Blind Stick with Emergency Alert System  
**Status:** Published 


---

##  Future Enhancements
- GPS-based location tracking
- Voice-based alerts
- AI-powered obstacle classification



---

