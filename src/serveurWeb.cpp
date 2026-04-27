// --------------------------------
//
//      serveurWeb.cpp
//
// --------------------------------
#include <Arduino.h>

#include "serveurWeb.hpp"
#include "flash.hpp"

// Créez un serveur sur le port 80
ESP8266WebServer server(80);

// Fonction pour gérer les requetes au serveur
void serveurWebHandleClient() {
    // Serial.println("Gestion des clients...");
    server.handleClient();
}

// Fonction pour gérer la page d'accueil
void handleRoot() {
    Serial.println("Affichage de la page d'accueil...");
    // String html = "<html><body><h1>Hello from ESP8266!</h1><p>Page d'accueil du serveur web.</p></body></html>";
    String html = flashFileRead("index.html",'t');
    server.send(200, "text/html", html);
}

void handleStyleCss() {
    Serial.println("Affichage de la page de style");
    String html = flashFileRead("style.css",'t');
    server.send(200, "text/css", html);
}

void handleMainJs() {
    Serial.println("Affichage de la page main.js");
    String html = flashFileRead("main.js",'t');
    server.send(200, "text/javascript", html);
}

void handleBundleJs() {
    Serial.println("Affichage de la page main.js (bundle.js)");
    String html = flashFileRead("bundle.js",'t');
    server.send(200, "text/javascript", html);
}

void handleFavicon() {
    Serial.println("Affichage de l'icone' (favicon.png)");
    String html = flashFileRead("favicon.png",'b');
    server.send(200, "image/x-icon", html);
}

void handleFilenotFound() {
    Serial.println("Affichage de la page not found");
    String html = flashFileRead("pageNotFound.html",'t');
    server.send(200, "text/html", html);
}

void serveurWebInit(){
    Serial.println("Initialisation du serveur web...");
    server.on("/", handleRoot);
    server.on("/style.css", handleStyleCss);
    server.on("/main.js", handleMainJs);
    server.on("/bundle.js", handleBundleJs);
    server.on("/favicon.png", handleBundleJs);
    server.onNotFound(handleFilenotFound);

    // Démarrer le serveur
    server.begin();
    Serial.println("Serveur web démarré");
};
