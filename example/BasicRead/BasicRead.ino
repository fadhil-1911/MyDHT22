#include <MyDHT22.h>

MyDHT22 dht(2); // DHT22 on pin D2

void setup() {
  Serial.begin(9600);
}

void loop() {
  dht.read();
  Serial.print("Temperature: ");
  Serial.print(dht.getTemperature());
  Serial.print(" °C, Humidity: ");
  Serial.print(dht.getHumidity());
  Serial.println(" %");
  delay(2000);
}
