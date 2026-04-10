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

//   // Connexion au Wi-Fi
//   WiFi.begin(localWifiSsid, localWifiPwd);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connexion en cours...");
//   }
//   Serial.println("Connecté au Wi-Fi : " + WiFi.SSID());
//   Serial.println("adresse IP : " + WiFi.localIP().toString());
  
//   // Définir les routes
//   server.on("/", handleRoot);
  
//   // Démarrer le serveur
//   server.begin();
//   Serial.println("Serveur web démarré");
}

// --------------------------------
//
//      LOOP
//
// --------------------------------
void loop() {
//   routeurWifiHandleClient();
  serveurWebHandleClient();
}

