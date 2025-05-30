#ifndef DETECTOR_H
#define DETECTOR_H
#include <Arduino.h>

const int analogInPin = A0; // ESP8266 Analog Pin ADC0 = A0
void chechMetal()
{

    int sensorValue = 0; // value read from the pot

    sensorValue = analogRead(analogInPin);

    // print the readings in the Serial Monitor
    // Serial.print("sensor = ");
    // Serial.print(sensorValue);
}

#endif
