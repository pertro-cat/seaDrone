#include <Arduino.h>
#include <ESP8266mDNS.h>
#include <LittleFS.h>

#include "variable.h"
#include "ultraSonic.h"
#include "wiFi.h"
#include "clock.h"
#include "convertToJson.h"
#include "motor.h"
#include "sendToBackEnd.h"
#include "accelerometr.h"
#include "metalDetector.h"

unsigned long lastJsonTime = 0;
// unsigned long jsonTime = 900000;
unsigned long jsonTime = 10000;

void updateJson()
{
  if ((millis() - lastJsonTime) > jsonTime)
  {
    String jsonStr = convertToJson(timeBuffer, distanceCm, minDistance, maxDistance, lot, lat, sensorValue);
    printJson(jsonStr);
    sendToServer(timeBuffer, distanceCm, minDistance, maxDistance, lot, lat, sensorValue);

    lastJsonTime = millis();
  }
}

void setup()
{
  Serial.begin(9600);
  ultraSonicSetup();
  connectWiFi();
  setupTime();
  InitWebServer();
  setupMotor();
  InitMDNS();
  accelerometrSetup();
}

void loop()
{
  ultraSonicUpdate();
  MDNS.update();
  getTime();
  updateJson();
  handleAccelerometr();
}
