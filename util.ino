void pinSetup() {
  pinMode(led, OUTPUT);
}


void wifiSetup() {
  bool res;
    // res = wm.autoConnect(); // auto generated AP name from chipid
    // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
    res = wm.autoConnect("ESP32","password"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
    }
}



void blinkLed(int ms) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= ms) {
    previousMillis = currentMillis;
    digitalWrite(led, !digitalRead(led));
  }
}
