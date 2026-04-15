//----------------------------------------------
//
//      sdCard.cpp
//
//----------------------------------------------

#include <Arduino.h>

#include <SPI.h>
#include <SD.h>

#include "sdCard.hpp"

// change this to match your SD shield or module;
// WeMos Micro SD Shield V1.0.0: D8
// LOLIN Micro SD Shield V1.2.0: D4 (Default)
// Feather ESP32 HUZZAH : ?? 
#ifdef lolin_s2_mini
    const int chipSelect = D4;
#elif wemos_d1_mini32 
    const int chipSelect = D8;
#elif adafruit_feather_m0 
    const int chipSelect = 5;
#else 
    #error Unsupported board selection.
#endif

File myFile;
String environnement;
bool insideEnvironnement;
int pin_relai;
int SdChauffageOnOff;
int SdConsigne;
boolean SDCardInitOK=false;

//----------------------------------------------
//
//      sdCardOpenFile
//
//----------------------------------------------
File sdCardOpenFile(char *filename){
    String ligne;
    return SD.open(filename);
}

//----------------------------------------------
//
//      sauvegardeFichier
//
//----------------------------------------------
void sauvegardeFichier(String filename, String datas){
    // filename = homeDir + filename;
    if (SD.exists(filename)){
        SD.remove(filename);
    }
    myFile = SD.open(filename, FILE_WRITE);
    if (myFile){
        //Serial.println("sdCard => sauvegarde de " + filename);
        myFile.print(datas);
        myFile.close();
        //Serial.print("sdCard => taille du fichier : ");
        //Serial.println(sizeof(datas));
    } else {
        Serial.print("impossible d'ouvrir le fichier ");
        Serial.print(filename);
        Serial.println();
    }
}

//----------------------------------------------
//
//      lireFichier
//
//----------------------------------------------
String lireFichier(String filename){
    // filename = homeDir + filename;
    char car;
    String buffer = "";
    myFile = SD.open(filename);
    // delay(10);
    if (myFile){
        // Serial.print("SDCard : lireFichier => lecture de " + filename);
        while(myFile.available()){
            car = myFile.read();
            buffer += car;
        }
        myFile.close();
        // Serial.print(" (");
        // Serial.print(buffer.length());
        // Serial.println(" octets)");
        // Serial.println("SDCard : lireFichier => contenu du fichier : " + buffer);
    } else {
        Serial.println("impossible d'ouvrir le fichier " + filename);
        // Serial.print(filename);
        // Serial.println();
    }
    // delay(10);
    // Serial.println("fin de la lecture du fichier " + filename);
    // // Serial.println("SDCARD => datas : " + buffer.length());
    // Serial.println(buffer);
    // Serial.println("SDCard : lireFichier => fin ");
    return buffer;
}

//----------------------------------------------
//
//      sdcardInit
//
//----------------------------------------------
bool sdcardInit(void){

    Serial.print("Initializing SD card  ...   ");

#ifdef lolin_s2_mini
    if (!SD.begin(chipSelect)) {
# else 
    if (!SD.begin()) {
# endif
        Serial.println("initialization failed!");
        SDCardInitOK=false;
        return false;
    }
    Serial.println("initialization done.");
    SDCardInitOK=true;
    return true;
}