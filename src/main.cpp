#include <Arduino.h>
#include <ESP8266mDNS.h>

#include "variable.h"
#include "ultraSonic.h"
#include "wiFi.h"
#include "clock.h"

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
}
