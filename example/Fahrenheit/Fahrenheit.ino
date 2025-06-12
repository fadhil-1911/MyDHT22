#include <MyDHT22.h>

MyDHT22 dht(2);

float toFahrenheit(float celsius) {
  return (celsius * 9.0 / 5.0) + 32;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (dht.read()) {
    float tempC = dht.getTemperature();
    float tempF = toFahrenheit(tempC);
    Serial.print("Temp: ");
    Serial.print(tempF);
    Serial.print(" °F, Humidity: ");
    Serial.print(dht.getHumidity());
    Serial.println(" %");
  } else {
    Serial.println("Sensor error");
  }
  delay(2000);
}
