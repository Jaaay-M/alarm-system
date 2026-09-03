#include <Arduino.h>
#include <ArduinoJson.h>
#include <BluetoothSerial.h>

#include "alarm.h"
#include "systemData.h"
#include "api.h"

// Create a BluetoothSerial object
BluetoothSerial SerialBT;

void setupBluetooth() {
    SerialBT.begin("Receiver");

    Serial.println("Bluetooth device is ready to pair");
}

void handleBluetooth() {

    // Check if data is available from the Bluetooth device
    if (SerialBT.available()) {
        String incomingData = SerialBT.readStringUntil('\n');

        // Print the received data to the Serial Monitor
        Serial.println("Bluetooth data received: " + incomingData);

        // Parse the incoming JSON data
        JsonDocument doc;

        // Deserialize the JSON data
        DeserializationError error = deserializeJson(doc, incomingData);

        // Check for errors in deserialization
        if (error) {
            Serial.print("Failed to parse JSON: ");
            Serial.println(error.c_str());
            return;
        }

        // Update the system status based on the received JSON data
        systemOnline = doc["online"] | false;
        systemTripped = doc["tripped"] | false;

        Serial.print("Data updated");
    }

}


