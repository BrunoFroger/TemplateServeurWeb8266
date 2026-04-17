// --------------------------------
//
//      flash.cpp
//
// --------------------------------
#include <Arduino.h>
#include <LittleFS.h> 

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
void flashInit(void){
    if (!LittleFS.begin()) {
        Serial.println("Echec du montage LITTLEFS");
        return;
    } else {
        Serial.println("montage LITTLEFS OK");
        listDir();
    }
}

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
