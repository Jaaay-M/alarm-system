#include <Arduino.h>

#include "variables.h"

void setup() {
  // Opens port 9600 for serial communication
  Serial.begin(9600);

  // Function to set up Bluetooth connection
  void setupBluetooth();

  // Function to set up the motion sensor
  void setupMotionSensor();
}

void loop() {
  // Function to read the distance from the ultrasonic sensor
  void motionSensorPulse();
}