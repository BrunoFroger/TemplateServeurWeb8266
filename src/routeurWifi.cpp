// --------------------------------
//
//      routeurWifi.cpp
//
// --------------------------------
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "routeurWifi.hpp"
#include "erreurs.h"



void routeurWifiInit(String ssid, String passwd){
    Serial.println("Initialisation du routeur Wi-Fi...");
    // Connexion au Wi-Fi
    WiFi.begin(ssid, passwd);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connexion en cours...");
    }
    Serial.println("Connecté au Wi-Fi : " + WiFi.SSID());
    Serial.println("adresse IP : " + WiFi.localIP().toString());
    Serial.println("Initialisation du serveur web...");
}

