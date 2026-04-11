// --------------------------------
//
//      serveurWeb.cpp
//
// --------------------------------
#include <Arduino.h>

#include "serveurWeb.hpp"
#include "sdCard.hpp"

// Créez un serveur sur le port 80
ESP8266WebServer server(80);

// Fonction pour gérer la page d'accueil
void serveurWebHandleClient() {
    // Serial.println("Gestion des clients...");
    server.handleClient();
}

// Fonction pour gérer la page d'accueil
void handleRoot() {
    Serial.println("Affichage de la page d'accueil...");
    String buffer = "";
    buffer =lireFichier("/template/index.html");
    // Serial.println("handleRoot => Contenu du fichier : " + buffer);
    // String html = "<html><body><h1>Hello from ESP8266!</h1><p>Page d'accueil du serveur web.</p></body></html>";
    server.send(200, "text/html", buffer);
}

void serveurWebInit(){
    Serial.println("Initialisation du serveur web...");
    server.on("/", handleRoot);

    // Démarrer le serveur
    server.begin();
    Serial.println("Serveur web démarré");
};
