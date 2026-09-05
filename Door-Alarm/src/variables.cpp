#include <Arduino.h>

#include "variables.h"

// Declare the variables as extern to indicate they are defined elsewhere
extern float distance = 0.0;
extern long duration = 0;

// ESP32 GPIO pins for the HC-SR04 ultrasonic sensor
#define echoPin 26
#define trigPin 27
const int buzzer = 25;