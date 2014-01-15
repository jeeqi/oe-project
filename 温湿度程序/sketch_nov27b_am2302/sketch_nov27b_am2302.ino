/*
  AM2302 Temperature / Humidity Sensor (DHT22)
  
  Current Code
  Created by Derek Erb 30/01/2013
  Modified 30/01/2013
  
  Requirement : Arduino + AM2302 sensor connected to pin 2
  
  DHT Library from:
  https://github.com/adafruit/DHT-sensor-library

  v0.03 Delays and formatting
  v0.02 Delay 3 seconds between readings
*/

#include "DHT.h"          // DHT & AM2302 library

// Version number
const float fVerNum = 0.03;

// Data pin connected to AM2302
#define DHTPIN 2

#define DHTTYPE DHT22       // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);   // LED pins

//////////////////////////////////////////////////////
//
// SETUP
//
void setup() {
  // Setup serial monitor
  Serial.begin(9600);
  
  // Wait 3 seconds
  delay(3000);
  
  Serial.println(F("\nAM2302 Sensor"));
  Serial.print(F("Version : "));
  Serial.println(fVerNum);
  Serial.println(F("Arduino - Derek Erb\n"));
  delay(5000);
  
  dht.begin();
}
  

void loop() {
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println(F("Failed to read from DHT"));
  }
  else {
    Serial.print(F("Humidity: ")); 
    Serial.print(h);
    Serial.print(F(" %\t"));
    Serial.print(F("Temperature: ")); 
    Serial.print(t);
    Serial.println(F(" C"));
  }
  
  // Wait 3 seconds
  delay(3000);
}


