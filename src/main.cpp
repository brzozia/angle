#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>
#include <ESP8266WiFi.h>

// put function declarations here:
RH_ASK driver(2000, D7, D6, D5);
const uint8_t PROX_SENSOR_PIN = 16; // GPIO16

void setup()
{
  WiFi.mode(WIFI_OFF);
  if (WiFi.getMode() == WIFI_OFF)
  {
    Serial.println(F("\nWifi mode is WIFI_OFF, until it is explicitly changed"));
  }
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PROX_SENSOR_PIN, INPUT);
  Serial.begin(9600);

  if (!driver.init())
    Serial.println("initialised");
}

void loop()
{
  while (1)
  {
    if (digitalRead(PROX_SENSOR_PIN) == LOW)
    {
      Serial.println("wlelcial-pieniazek"); // Check the sensor output{
      digitalWrite(LED_BUILTIN, HIGH);

      const uint8_t msg = 1;
      if (driver.send(&msg, 8))
      {
        Serial.print("sent!");
      }
      driver.waitPacketSent();
      digitalWrite(LED_BUILTIN, LOW);
    }
    delay(5);
  }
}
