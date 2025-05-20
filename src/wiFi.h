#ifndef WIFI_H
#define WIFI_H
#define HOST_NAME "sea-drone"
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

// #include "index_html.h"
#include "variable.h"

// Replace with your network credentials
const char *ssid = "admin";
const char *password = "domestos1216";

AsyncWebServer server(80);

void InitMDNS()
{
    if (!MDNS.begin(HOST_NAME))
    {
        Serial.println("Error starting mDNS");
    }
    MDNS.addService("http", "tcp", 80);
    Serial.println("mDNS started");
}

void connectWiFi()
{
    WiFi.begin(ssid, password);
    Serial.println("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.println(WiFi.localIP());
}

#endif