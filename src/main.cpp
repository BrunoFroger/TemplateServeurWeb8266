// --------------------------------
//
//      main.cpp
//
// --------------------------------
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h> 

#include "routeurWifi.hpp"
#include "serveurWeb.hpp"
#include "erreurs.h"

String flashFileRead (const char *filename){
    String buffer = "";
    File file;
    file = LittleFS.open(filename, "r");
    if (!file || file.isDirectory()) {
        Serial.println("...echec de la lecture...ce fichier existe-t-il?");
    } else {
        while (file.available()) {
            buffer += char(file.read());
        }
    }
    return buffer;
}

void listDir() {
  Serial.println("Liste des fichiers:");

  Dir dir = LittleFS.openDir ("");
  while (dir.next ()) {
    Serial.print("  Nom: ");
    Serial.print (dir.fileName ());
    Serial.print("\tTaille: ");
    Serial.println (dir.fileSize ());
  }

  Serial.println();
}


// --------------------------------
//
//      SETUP
//
// --------------------------------
void setup() {
    Serial.begin(460800);
    routeurWifiInit(localWifiSsid, localWifiPwd);
    serveurWebInit();
    if (!LittleFS.begin()) {
        Serial.println("Echec du montage LITTLEFS");
        return;
    } else {
        Serial.println("montage LITTLEFS OK");
        listDir();
    }
}

// --------------------------------
//
//      LOOP
//
// --------------------------------
void loop() {
  serveurWebHandleClient();
}

