/*
   ESP32 FastLED WebServer: https://github.com/jasoncoon/esp32-fastled-webserver
   Copyright (C) 2017 Jason Coon

   Built upon the amazing FastLED work of Daniel Garcia and Mark Kriegsman:
   https://github.com/FastLED/FastLED

   ESP32 support provided by the hard work of Sam Guyer:
   https://github.com/samguyer/FastLED

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <Secrets.h>


// AP mode password
char WiFiAPPSK[] = "your-password";

// Wi-Fi network to connect to (if not in AP mode)
#define WIFI_NETWORK  "your-ssid"
#define WIFI_PASSWORD "your-password"

#define WIFI_TIMEOUT  20000

//#define HOSTNAME "ESP32-" ///< Hostname. The setup function adds the Chip ID at the end.

//const bool apMode = false;

// AP mode password
//const char WiFiAPPSK[] = "";

void connectToWIFI(){
  Serial.print("Connecting to wifi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_NETWORK,WIFI_PASSWORD);


  unsigned long startAttemptTime = millis();

  while(WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT){
    Serial.print(".");
    delay(100);
  }

  if (WiFi.status() != WL_CONNECTED ){
    Serial.print("Failed!");
    //ESP.reset();
  }else{
    Serial.print("Connected!!!");
    Serial.print(WiFi.localIP());
  }
}
