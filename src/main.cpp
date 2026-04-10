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




// --------------------------------
//
//      SETUP
//
// --------------------------------
void setup() {
    Serial.begin(460800);
    routeurWifiInit(localWifiSsid, localWifiPwd);
    serveurWebInit();
}

// --------------------------------
//
//      LOOP
//
// --------------------------------
void loop() {
  serveurWebHandleClient();
}

