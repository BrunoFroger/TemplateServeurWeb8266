// --------------------------------
//
//      main.cpp
//
// --------------------------------
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "routeurWifi.hpp"
#include "serveurWeb.hpp"
#include "erreurs.h"
#include "sdCard.hpp"

// --------------------------------
//
//      SETUP
//
// --------------------------------
void setup() {
    Serial.begin(460800);
    routeurWifiInit(localWifiSsid, localWifiPwd);
    serveurWebInit();
    sdcardInit();
}

// --------------------------------
//
//      LOOP
//
// --------------------------------
void loop() {
  serveurWebHandleClient();
}

