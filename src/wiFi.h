#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>
#include <LittleFS.h>
#include "motor.h"

#define HOST_NAME "sea-drone"

const char *ssid = "admin";
const char *password = "domestos1216";

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void onWebSocketEvent(AsyncWebSocket *server,
                      AsyncWebSocketClient *client,
                      AwsEventType type,
                      void *arg,
                      uint8_t *data,
                      size_t len)
{
    if (type == WS_EVT_CONNECT)
    {
        Serial.println("WebSocket підключено");
        client->text("OK");
    }
    else if (type == WS_EVT_DATA)
    {
        String msg = "";
        for (size_t i = 0; i < len; i++)
            msg += (char)data[i];
        Serial.println("Команда: " + msg);

        // Тут обробка команд:
        if (msg.startsWith("SPEED:"))
        {
            int speed = msg.substring(6).toInt();
            Serial.printf("Швидкість: %d\n", speed);
        }
        else if (msg == "UP")
        {
            Serial.println("Вперед");
            // тут код керування моторами вперед
            forward();
        }
        else if (msg == "DOWN")
        {
            Serial.println("Назад");
            // тут код керування моторами назад
            backward();
        }
        else if (msg == "LEFT")
        {
            Serial.println("Вліво");
            // тут код повороту або руху вліво
            left();
        }
        else if (msg == "RIGHT")
        {
            Serial.println("Вправо");
            // тут код повороту або руху вправо
            right();
        }
    }
}

void InitWebServer()
{
    ws.onEvent(onWebSocketEvent);
    server.addHandler(&ws);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send(LittleFS, "/index.html", "text/html"); });

    server.serveStatic("/", LittleFS, "/");

    server.begin();
}

void InitMDNS()
{
    if (!MDNS.begin(HOST_NAME))
    {
        Serial.println("mDNS помилка");
    }
    MDNS.addService("http", "tcp", 80);
    Serial.println("mDNS активний");
}

void connectWiFi()
{
    WiFi.begin(ssid, password);
    Serial.print("Підключення до WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.print("IP адреса: ");
    Serial.println(WiFi.localIP());

    if (!LittleFS.begin())
    {
        Serial.println("LittleFS Mount Failed");
        return;
    }
}

#endif
