#include <Arduino.h>
#include <RH_ASK.h>
#include <SPI.h>

// put function declarations here:
RH_ASK driver(2000, D7, D6, D5);
const uint8_t PROX_SENSOR_PIN = 16; // GPIO16

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PROX_SENSOR_PIN, INPUT);
  Serial.begin(9600);
  
  if (!driver.init())
    Serial.println("initialised");
}

void loop()
{
  while (1){
    delay(5);
    if (digitalRead(PROX_SENSOR_PIN) == LOW){  
      Serial.println("dupa");    
      Serial.println(digitalRead(PROX_SENSOR_PIN));                   // Check the sensor output{
      digitalWrite(LED_BUILTIN, HIGH);
      const char *msg = "ala";
      boolean send_info = driver.send((uint8_t *)msg, strlen(msg));
      if (send_info)
      {
        Serial.print(8);
      }
      driver.waitPacketSent();
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
