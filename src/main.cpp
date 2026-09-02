#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <LittleFS.h>

#include "hidden.h"
#include "api.h"
#include "alarm.h"

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setup() {

  // Start Serial communication for debugging
  Serial.begin(115200);

  LittleFS.begin();

  if (!LittleFS.begin(true)) {
    Serial.println("An error has occurred while mounting LittleFS");
    return;
  }

  else {
    Serial.println("LittleFS mounted successfully");
  }

  Serial.println(LittleFS.exists("/index.html") ? "index.html exists" : "index.html does not exist");
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();

  // Print the successful connection message and the IP address
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  setupBluetooth();
  
  // Serve the index.html file when accessing the root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html", "text/html");
  });

  server.begin();
  setupAPI(server);
  Serial.println("HTTP server started");
}

void loop() {
  handleBluetooth();
  // Nothing to do here, everything is handled asynchronously
}