#include <MyDHT22.h>

MyDHT22 dht(2); // DHT22 on pin D2

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (dht.read()) {
    Serial.print("Temp: ");
    Serial.print(dht.getTemperature());
    Serial.print(" °C, Humidity: ");
    Serial.print(dht.getHumidity());
    Serial.println(" %");
  } else {
    Serial.println("Sensor read failed!");
  }
  delay(2000);
}
