#include <Arduino.h>
#include <BluetoothSerial.h>

#include "hidden.h"
#include "bluetooth.h"

// ESP32 GPIO pins for the HC-SR04 ultrasonic sensor
#define echoPin 26
#define trigPin 27

// ESP32 GPIO pin for the buzzer
const int buzzer = 25;

// Variables for the ultrasonic sensor
long duration;
float distance;

void setup() {
  // Opens port 9600 for serial communication
  Serial.begin(9600);

  // Function to set up Bluetooth connection
  void setupBluetooth();

  // Sets the HC-SR04 pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Sets the buzzer pin as an OUTPUT
  pinMode(buzzer, OUTPUT);

  // Make sure the buzzer starts off
  noTone(buzzer);
}

void loop() {

  // Function to read the distance from the ultrasonic sensor
  void motionSensorPulse();

  // If the distance is greater than 10 cm, sound the buzzer
  if (distance > 5) {
    tone(buzzer, 1000);
    delay(500);
    tone(buzzer, 750);
    delay(500);
    void updatesBluetooth();
  } else {
    noTone(buzzer);
    delay(100);
    void updatesBluetooth();
  }
}