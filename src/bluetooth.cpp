#include <Arduino.h>
#include <ArduinoJson.h>
#include <BluetoothSerial.h>

#include "hidden.h"

BluetoothSerial SerialBT;

void setupBluetooth() {
    Serial.begin(9600);

    Serial.println("Starting Bluetooth...");

    SerialBT.begin("Alarm", true);

    Serial.println("Attempting Bluetooth connection...");

    bool connected = SerialBT.connect(serverAddress);

    if (connected)
    {
        Serial.println("Bluetooth connected!");
    }
    else
    {
        Serial.println("Bluetooth connection failed.");
    }
}

void updatesBluetooth() {
    if (SerialBT.connected()) {
    }
}