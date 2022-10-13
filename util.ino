void pinSetup() {
  pinMode(led, OUTPUT);
}


void wifiSetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
}



void blinkLed(int ms) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= ms) {
    previousMillis = currentMillis;
    digitalWrite(led, !digitalRead(led));
  }
}
