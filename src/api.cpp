#include <ArduinoJson.h>
#include "api.h"

// Temporary variables to hold the system status. In a real application, these would be updated based on actual system state.
bool systemOnline = false;
bool systemTripped = false;

// Sets up the API endpoints for the web server
void setupAPI(AsyncWebServer &server) {
  server.on("/api/status", HTTP_GET, [](AsyncWebServerRequest *request){

    // Create a JSON document to hold the system status
    JsonDocument doc;

    doc["Online"] = systemOnline;
    doc["Tripped"] = systemTripped;

    // Serialize the JSON document to a string
    String json;
    serializeJson(doc, json);

    // Send the JSON response back to the client
    request->send(200, "application/json", json);
  });
}