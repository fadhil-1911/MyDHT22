# MyDHT22

Library for reading DHT22 temperature and humidity sensor without using any external library.

## Example

```cpp
#include <MyDHT22.h>

MyDHT22 dht(2);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (dht.read()) {
    Serial.print("Temp: ");
    Serial.print(dht.getTemperature());
    Serial.print("°C  Humidity: ");
    Serial.print(dht.getHumidity());
    Serial.println("%");
  } else {
    Serial.println("Failed to read from DHT22");
  }
  delay(2000);
}
```
