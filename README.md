# esp32-fastled-webserver
Work in progress ESP32 port of https://github.com/jasoncoon/esp8266-fastled-webserver


- Converted to PIO
- ESP32 nodeMCU not connecting to wifi. Issue corrected.
- Added support for White LED's using Adafruit lib and RGB to RGBW conversion (see http://codewelt.com/rgbw). Note fast LED is used to generate all colors and patterns then its converted to RGBW then sent to Adifruit lib to display.

NEXT Steps:
Add direct control for white LED.
Add Alexa App control.
