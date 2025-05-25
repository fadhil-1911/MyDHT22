#include <MyDHT22.h>

MyDHT22 dht(2); // Sambung ke pin D2

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (dht.read()) {
    Serial.print("Suhu: ");
    Serial.print(dht.getTemperature());
    Serial.print(" °C, Kelembapan: ");
    Serial.print(dht.getHumidity());
    Serial.println(" %");
  } else {
    Serial.println("Gagal baca sensor!");
  }
  delay(2000);
}
