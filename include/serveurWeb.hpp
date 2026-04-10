// --------------------------------
//
//      routeurWifi.hpp
//
// --------------------------------
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "erreurs.h"

#ifndef __SERVEURWEB__
#define __SERVEURWEB__

    extern ESP8266WebServer server;
    extern void serveurWebInit(void);
    extern void serveurWebHandleClient(void);
    // class ServeurWeb {
    //     public:
    //         void init();
    //         void handleClient(void);

    //     private:
    //         ESP8266WebServer server(80);
    //         void handleRoot(void);
    // };

#endif