#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#define CARD_MODULE_PIN 10
#define SWITCH_PIN 9
SoftwareSerial BTSerial(2, 3);

int state = 0;

File myFile; 

void setup() {
    Serial.begin(115200);
    BTSerial.begin(115200);
    if (!SD.begin(CARD_MODULE_PIN)) {
        while (1);
    }
}

void loop() {
    auto val = analogRead(A6);
    Serial.println(val);
    if (SD.exists("test.txt")){
        myFile = SD.open("test.txt", FILE_WRITE);
        myFile.println(val);
        myFile.close();
    }
    if(BTSerial.available()){
        BTSerial.println(val);
    }
    delay(10);
}