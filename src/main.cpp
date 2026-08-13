#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <LittleFS.h>

// Replace with your network credentials
const char* ssid = "BLANK";
const char* password = "BLANK";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

void setup() {

  // Start Serial communication for debugging
  Serial.begin(115200);

  // Initialize LittleFS
  if (!LittleFS.begin()) {
    Serial.println("An error has occurred while mounting LittleFS");
    return;
  }

  Serial.println("LittleFS mounted successfully");

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Print the successful connection message and the IP address
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
  Serial.println("HTTP server started");

  // Serve the index.html file when accessing the root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html", "text/html");
  });

}