#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>

// Motor A connections
int enA = 15;
int in1 = 13;
int in2 = 12;

// Motor B connections
int enB = 14;
int in3 = 0;
int in4 = 2;

void setupMotor()
{
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}
void setSpeed(int speed)
{
    speed = constrain(speed, 0, 255); // Обмеження в межах 0–255
    analogWrite(enA, speed);
    analogWrite(enB, speed);
}
void forward()
{
    Serial.println("fn forward");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void backward()
{
    Serial.println("fn backward");

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
void left()
{
    Serial.println("fn left");
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void right()
{
    Serial.println("fn right");

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
void Stop()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

#endif