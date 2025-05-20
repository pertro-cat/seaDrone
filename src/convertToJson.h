#ifndef CONVERTJSON_H
#define CONVERTJSON_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include "ultraSonic.h"
#include "clock.h"
#include "variable.h"

String convertToJson(const String &timeBuffer, float distanceCm, float minDistance, float maxDistance, String lot, String lat)
{
    JsonDocument doc;

    doc["time"] = timeBuffer;
    doc["distanceCm"] = distanceCm;
    doc["minDistance"] = minDistance;
    doc["maxDistance"] = maxDistance;
    doc["lot"] = lot;
    doc["lat"] = lat;

    String output;
    serializeJson(doc, output);
    return output;
}

// Для відлагодження
void printJson(const String &json)
{
    Serial.println(json);
}

#endif