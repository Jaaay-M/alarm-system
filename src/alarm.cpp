#include <Arduino.h>
#include <BluetoothSerial.h>
#include "alarm.h"

// Create a BluetoothSerial object
BluetoothSerial SerialBT;

void setup() {
    SerialBT.begin("Receiver");
}

void loop() {

}


