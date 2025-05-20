#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include <Arduino.h>
#include "variable.h"

void minDist()
{
    if (distanceCm < minDistance)
    {
        minDistance = distanceCm;
    }
    Serial.print("Min Distance: ");
    Serial.println(minDistance);
}

void maxDist()
{
    if (distanceCm > maxDistance)
    {
        maxDistance = distanceCm;
    }
    Serial.print("Max Distance: ");
    Serial.println(maxDistance);
}

void ultraSonicSetup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW); // Обов’язково скидаємо тригер
}

void ultraSonicUpdate()
{
    if ((millis() - lastTime) > UPDATE_TIME)
    {
        // Стандартний запуск без затримок
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        duration = pulseIn(echoPin, HIGH);
        distanceCm = duration * SOUND_SPEED / 2;

        Serial.print("Distance (cm): ");
        Serial.println(distanceCm);

        minDist();
        maxDist();

        lastTime = millis();
    }
}

#endif