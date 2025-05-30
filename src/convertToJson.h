#ifndef CONVERTJSON_H
#define CONVERTJSON_H
#include <Arduino.h>
#include <ArduinoJson.h>
#include "ultraSonic.h"
#include "metalDetector.h"
#include "clock.h"
#include "variable.h"

// extern int sensorValue;

String convertToJson(const String &timeBuffer, float distanceCm, float minDistance, float maxDistance, String lot, String lat, int sensorValue)
{
    JsonDocument doc;

    doc["time"] = timeBuffer;
    doc["distanceCm"] = distanceCm;
    doc["minDistance"] = minDistance;
    doc["maxDistance"] = maxDistance;
    doc["lot"] = lot;
    doc["lat"] = lat;
    doc["sensorValue"] = sensorValue;

    String output;
    serializeJson(doc, output);
    return output;
}

// Для відлагодження
void printJson(const String &json)
{
    // Serial.println(json);
}

#endif