// --------------------------------
//
//      routeurWifi.hpp
//
// --------------------------------
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "erreurs.h"

#ifndef __ROUTEURWIFI__
#define __ROUTEURWIFI__

    extern void routeurWifiInit(String ssid, String passwd);

#endif