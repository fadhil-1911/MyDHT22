#include <MyDHT22.h>

MyDHT22 dht(2);
unsigned long lastRead = 0;
const unsigned long interval = 5000; // 5 seconds

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() - lastRead >= interval) {
    lastRead = millis();
    if (dht.read()) {
      Serial.print("Temp: ");
      Serial.print(dht.getTemperature());
      Serial.print(" °C, Humidity: ");
      Serial.print(dht.getHumidity());
      Serial.println(" %");
    } else {
      Serial.println("Read error.");
    }
  }
}
