#include <Arduino.h>

#include "motionSensor.h"

// ESP32 GPIO pins for the HC-SR04 ultrasonic sensor
#define echoPin 26
#define trigPin 27

// Variables for the ultrasonic sensor
long duration;
float distance;

void motionSensorPulse() {
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sends a 10 microsecond trigger pulse
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, with a 30 milliseconds timeout
    duration = pulseIn(echoPin, HIGH, 30000);

    // If no echo was received, don't calculate a false distance
    if (duration == 0) {
    Serial.println("No echo received");
    delay(100);
    return;
    }

    // Calculate the distance in centimetres
    distance = duration * 0.034 / 2;

    // Print the distance on the Serial Monitor
    Serial.println("Distance: " + String(distance) + " cm");

}