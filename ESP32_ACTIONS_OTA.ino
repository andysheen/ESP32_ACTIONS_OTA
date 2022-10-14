#include <WiFiManager.h>
#include <HTTPClient.h>
#include <HTTPUpdate.h>
#include <WiFiClientSecure.h>
#include "cert.h"
#include "fw_version.h"

WiFiManager wm;

#define URL_fw_Version "https://raw.githubusercontent.com/andysheen/ESP32_ACTIONS_OTA/main/fw_version.h"
#define URL_fw_Bin  "https://raw.githubusercontent.com/andysheen/ESP32_ACTIONS_OTA/main/app.bin"


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

  blinkLed(100);

}
