#include <Arduino.h>
#include <ESP8266mDNS.h>

#include "variable.h"
#include "ultraSonic.h"
#include "wiFi.h"
#include "clock.h"
#include "convertToJson.h"

unsigned long lastJsonTime = 0;
// unsigned long jsonTime = 900000;
unsigned long jsonTime = 5000;

void updateJson()
{
  if ((millis() - lastJsonTime) > jsonTime)
  {
    String jsonStr = convertToJson(timeBuffer, distanceCm, minDistance, maxDistance, lot, lat);
    printJson(jsonStr);
    // sendToServer(timeBuffer, distanceCm, minDistance, maxDistance, lot, lat);

    lastJsonTime = millis();
  }
}

void setup()
{
  Serial.begin(115200);
  ultraSonicSetup();
  connectWiFi();
  setupTime();

  InitMDNS();
}

void loop()
{
  ultraSonicUpdate();
  MDNS.update();
  getTime();
  updateJson();
}
