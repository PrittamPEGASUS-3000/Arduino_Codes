//Pegasus-3000
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

//pins 2 and 3 to communicate
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(9600);//USB serial port for debugging
  softwareSerial.begin(9600);//serial port for DFPlayer Mini

  if (player.begin(softwareSerial)) {
    Serial.println("OK");

    player.volume(30);//volume set 0 to 30
    player.play(5);//1st file on SD card

  } else {
    Serial.println("Connecting failed!");
  }
}

void loop() {
  
}
