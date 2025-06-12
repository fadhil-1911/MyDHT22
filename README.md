# MyDHT22 Library

Lightweight Arduino library for reading temperature and humidity from DHT22 sensor.

## Key Features
- Temperature and humidity reading using digital protocols
- Lightweight and free from external library dependencies

## System Requirements
- Arduino IDE
- Boards like Arduino Nano, Uno, etc
- DHT22 sensor

## Installation Instructions
1. Download the ZIP file
2. Extract it into `Documents/Arduino/libraries/MyDHT22`
3. Open Arduino IDE and check the examples

## Important Notes
- Make sure the sensor is connected correctly (VCC, GND, and data pins)
- Can be used with any digital pin

## Usage Examples

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