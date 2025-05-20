#ifndef SEND_TO_BACKEND
#define SEND_TO_BACKEND

#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "convertToJson.h"

const char *serverName = "http://192.168.31.159:5000/api/tag_data/";

void sendToServer(const String &timeBuffer, float distanceCm, float minDistance, float maxDistance, String lot, String lat)
{
    HTTPClient http;
    WiFiClient client;

    http.begin(client, serverName);
    http.addHeader("Content-Type", "application/json");

    String jsonStr = convertToJson(timeBuffer, distanceCm, minDistance, maxDistance, lot, lat);

    int httpResponseCode = http.POST(jsonStr);

    Serial.print("Sending data: ");
    Serial.println(jsonStr);
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);

    if (httpResponseCode > 0)
    {
        String response = http.getString();
        Serial.print("Response from server: ");
        Serial.println(response);
    }
    else
    {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }

    http.end();
}

#endif
