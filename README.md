# MyDHT22 Library

Lightweight Arduino library for reading temperature and humidity from DHT22 sensor.

## Ciri-ciri Utama
- Bacaan suhu dan kelembapan menggunakan protokol digital
- Ringan dan bebas dari kebergantungan perpustakaan luar

## Keperluan Sistem
- Arduino IDE
- Papan seperti Arduino Nano, Uno, dll
- Sensor DHT22

## Cara Pemasangan
1. Muat turun fail ZIP
2. Ekstrak ke dalam `Documents/Arduino/libraries/MyDHT22`
3. Buka Arduino IDE dan semak contoh

## Nota Penting
- Pastikan sensor disambung dengan betul (VCC, GND, dan pin data)
- Boleh digunakan dengan mana-mana pin digital

## Contoh Penggunaan

```cpp
#include <MyDHT22.h>

MyDHT22 dht(2); // Pin D2

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (dht.read()) {
    Serial.print("Temp: ");
    Serial.print(dht.getTemperature());
    Serial.print(" C, Humidity: ");
    Serial.println(dht.getHumidity());
  }
  delay(2000);
}
```
