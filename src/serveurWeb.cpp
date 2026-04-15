// --------------------------------
//
//      serveurWeb.cpp
//
// --------------------------------
#include <Arduino.h>

#include "serveurWeb.hpp"
// Créez un serveur sur le port 80
ESP8266WebServer server(80);
extern String flashFileRead (const char *filename);

// Fonction pour gérer la page d'accueil
void serveurWebHandleClient() {
    // Serial.println("Gestion des clients...");
    server.handleClient();
}

// Fonction pour gérer la page d'accueil
void handleRoot() {
    Serial.println("Affichage de la page d'accueil...");
    // String html = "<html><body><h1>Hello from ESP8266!</h1><p>Page d'accueil du serveur web.</p></body></html>";
    String html = flashFileRead("index.html");
    server.send(200, "text/html", html);
}

void serveurWebInit(){
    Serial.println("Initialisation du serveur web...");
    server.on("/", handleRoot);

    // Démarrer le serveur
    server.begin();
    Serial.println("Serveur web démarré");
};
