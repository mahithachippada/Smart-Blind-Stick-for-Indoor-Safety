#include "BluetoothSerial.h"   // Built-in Bluetooth library for ESP32
BluetoothSerial BT;            // Create Bluetooth Serial object

#define TRIG_PIN 5
#define ECHO_PIN 18
#define WATER_PIN 34
#define BUZZER_PIN 23
#define PANIC_PIN 4   // Push button (active LOW)

long duration;
int distance;
int waterState;
int panicState;

void setup() {
  Serial.begin(115200);
  BT.begin("BlindStick_ESP32");   // Bluetooth device name
  Serial.println("Bluetooth device started, pair with 'BlindStick_ESP32'");

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(WATER_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PANIC_PIN, INPUT_PULLUP);

  Serial.println("ESP32 Blind Stick with Bluetooth Started");
  //BT.println("Blind Stick Connected");
}

void loop() {
  //  Ultrasonic sensor 
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;  // in cm

  //  Water sensor 
  waterState =1- digitalRead(WATER_PIN); // HIGH = Dry, LOW = Wet

  //  Panic button 
  panicState = digitalRead(PANIC_PIN); // LOW = Pressed

  //  Display info on Serial and Bluetooth 
  Serial.print("Dist: ");
  Serial.print(distance);
  Serial.print(" cm | Water: ");
  Serial.print(waterState == HIGH ? "Dry" : "Wet");
  Serial.print(" | Panic: ");
  Serial.println(panicState == LOW ? "Pressed" : "Normal");

  // Send the same info to phone via Bluetooth
  //BT.print("Distance: ");
  //BT.print(distance);
  //BT.print(" cm | Water: ");
  //BT.print(waterState == HIGH ? "Dry" : "Wet");
  //BT.print(" | Panic: ");
  //BT.println(panicState == LOW ? "Pressed" : "Normal");

  //  Panic button action 
  if (panicState == LOW) {  // Panic pressed
    Serial.println("PANIC ALERT!");
    BT.println("PANIC ALERT ACTIVATED!");
    delay(2000);

    // Continuous beeping for alert
    for (int i = 0; i < 10; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(150);
      digitalWrite(BUZZER_PIN, LOW);
      delay(150);
    }
  }
  //  Obstacle or water detection alert 
  else if ((distance < 25 && distance > 0)) {
    digitalWrite(BUZZER_PIN, HIGH);
    BT.println("OBSTACLE  DETECTED!");
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(2000);
  } 
  
  else if  (waterState == LOW) {
    digitalWrite(BUZZER_PIN, HIGH);
    BT.println("WATER DETECTED!");
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(2000);
  }
  
  else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000); // 1 second interval
}
