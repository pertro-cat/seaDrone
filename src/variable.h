#ifndef VARIABLE_H
#define VARIABLE_H
#include <Arduino.h>

const int trigPin = 5;
const int echoPin = 4;
unsigned long lastTime = 0;

#define SOUND_SPEED 0.034
#define UPDATE_TIME 2000

long duration;
float distanceCm;

float minDistance = 9999.0;
float maxDistance = 0.0;

String lot = "44.62336736580267";
String lat = "33.51391959994705";

char timeBuffer[32];

#endif