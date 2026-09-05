#include <Arduino.h>

#include "motionSensor.h"
#include "variables.h"

void setupMotionSensor() {
    // Sets the HC-SR04 pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Sets the buzzer pin as an OUTPUT
    pinMode(buzzer, OUTPUT);

    // Make sure the buzzer starts off
    noTone(buzzer);
}

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