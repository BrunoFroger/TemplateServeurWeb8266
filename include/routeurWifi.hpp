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

    // extern void routeurWifiHandleClient(void);
    extern void routeurWifiInit(String ssid, String passwd);

    // class RouteurWifi {
    //     public:
    //         void init(String ssid, String passwd);
    //         void handleClient(void);

    //     private:
    //         String ssid;
    //         String passwd;
    //         ESP8266WebServer server;
    //         void handleRoot(void);
    // };

#endif