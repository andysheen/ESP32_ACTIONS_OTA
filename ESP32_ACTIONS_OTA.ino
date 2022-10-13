#include <WiFiManager.h> 
#include <HTTPClient.h>
#include <HTTPUpdate.h>

 WiFiManager wm;

const char * GITHUB_URL = "https://github.com/andysheen/ESP32_ACTIONS_OTA/releases/latest/download/app.bin";

//LED Variables
const int led = 2; // ESP32 Pin to which onboard LED is connected
unsigned long previousMillis = 0;

void setup() {

  pinSetup();

  Serial.begin(115200);
  Serial.println("Booting");
  wifiSetup();

  otaHandler();
}

void loop() {

  blinkLed(1000);

}
