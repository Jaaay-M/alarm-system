#include <Arduino.h>
#include <BluetoothSerial.h>

#include "bluetooth.h"

void setup() {
  // Opens port 9600 for serial communication
  Serial.begin(9600);

  // Function to set up Bluetooth connection
  void setupBluetooth();

}

void loop() {

  // Function to read the distance from the ultrasonic sensor
  void motionSensorPulse();

}