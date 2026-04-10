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
//     this->ssid = ssid;
//     this->passwd = passwd;
    Serial.println("Initialisation du routeur Wi-Fi...");
    // Connexion au Wi-Fipasswd
    WiFi.begin(ssid, passwd);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connexion en cours...");
    }
    Serial.println("Connecté au Wi-Fi : " + WiFi.SSID());
    Serial.println("adresse IP : " + WiFi.localIP().toString());
    Serial.println("Initialisation du serveur web...");
    // ESP8266WebServer server(80);
    // Définir les routes
    // // server.on("/", [this]() { this->handleRoot(); });
    // server.on("/", handleRoot);

    // // Démarrer le serveur
    // server.begin();
    // Serial.println("Serveur web démarré");
}


// // Fonction pour gérer la page d'accueil
// void RouteurWifi::handleClient() {
//     // Serial.println("Gestion des clients...");
//     server.handleClient();
// }

// // Fonction pour gérer la page d'accueil
// void RouteurWifi::handleRoot() {
//   String html = "<html><body><h1>Hello from ESP8266!</h1><p>Page d'accueil du serveur web.</p></body></html>";
//   server.send(200, "text/html", html);
// }
