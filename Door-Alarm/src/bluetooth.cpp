#include <Arduino.h>
#include <ArduinoJson.h>
#include <BluetoothSerial.h>

#include "secret.h"
#include "variables.h"


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
        JsonDocument doc;

        if (distance > 5) {
            doc["Triggered"] = true;
        } else {
            doc["Triggered"] = false;
        }

        String jsonString;
        serializeJson(doc, jsonString);

        Serial.println("Sending JSON: " + jsonString);
    }
}