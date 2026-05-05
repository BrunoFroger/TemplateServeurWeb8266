// --------------------------------
//
//      flash.cpp
//
// --------------------------------
#include <Arduino.h>
#include <LittleFS.h> 

// #define __DEBUG__FLASH__

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

String flashFileRead (const char *filename, char mode){
    String buffer = "";
    File file;
    #ifdef __DEBUG__FLASH__
        Serial.println("lecture en flash du fichier : " + String(filename));
    #endif
    file = LittleFS.open(filename, "r");
    if (!file || file.isDirectory()) {
        Serial.println("...echec de la lecture...ce fichier existe-t-il?");
    } else {
        while (file.available()) {
            switch (mode) {
                case 't':
                case 'T':
                    buffer += char(file.read());
                    break;
                case 'b':
                case 'B':
                    buffer += file.read();
                    break;
                default:
                    Serial.printf("flashFileRead => mode %c inconnu\n", mode);
                    break;
            }
            // if (mode == 't'){
            //     buffer += char(file.read());
            // }
        }
        #ifdef __DEBUG__FLASH__
            Serial.println("------------------------------------");
            Serial.println(buffer);
            Serial.println("------------------------------------");
        #endif
    }
    return buffer;
}
