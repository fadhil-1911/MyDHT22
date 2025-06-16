
# MyDHT22 Library

**Lightweight Arduino library for reading temperature and humidity from DHT22 sensor.**

---

## Key Features
- Reads temperature (°C) and humidity (% RH) via digital signal
- Lightweight and fast – no external dependencies
- Non-blocking, optimized for microcontrollers

---

## System Requirements
- Arduino IDE
- Arduino-compatible board (e.g., Uno, Nano)
- DHT22 sensor connected to any digital pin

---

## Installation Instructions
1. Download the ZIP file from [GitHub](https://github.com/fadhil-1911/MyDHT22)
2. Extract it into `Documents/Arduino/libraries/MyDHT22`
3. Restart the Arduino IDE
4. Open **File > Examples > MyDHT22 > BasicRead**

---

## Important Notes
- Wire the sensor correctly (VCC to 3.3V/5V, GND to GND, DATA to digital pin)
- Use a 4.7k–10k pull-up resistor on the data pin (recommended)

---

## Example

```cpp
#include <MyDHT22.h>

// Connect DHT22 to digital pin 7
MyDHT22 dht(7);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting DHT22 reading...");
}

void loop() {
  if (dht.readData()) {
    float temperature = dht.getTemperature();
    float humidity = dht.getHumidity();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    Serial.println("Failed to read data from DHT22");
  }

  delay(2000); // read every 2 seconds
}

⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

API Reference – MyDHT22

⸻⸻⸻⸻⸻⸻⸻⸻⸻⸻

## Constructor

## MyDHT22(uint8_t pin)

Initializes the DHT22 sensor on the specified digital pin.
	•	Parameters:
	•	pin – Arduino digital pin connected to the DHT22 data pin.
	•	Example:

MyDHT22 dht(7); // Uses digital pin 7

⸻

## readData()

bool readData()

Reads new data from the DHT22 sensor.
	•	Returns: true if reading is successful and checksum is valid, false otherwise.
	•	Must be called before accessing temperature or humidity.

if (dht.readData()) {
  // safe to call getTemperature() and getHumidity()
}

⸻

## getTemperature()

float getTemperature()

Returns the last temperature reading in degrees Celsius.
	•	Return Type: float
	•	Note: Call only after readData() returns true.

float temp = dht.getTemperature();

⸻

## getHumidity()

float getHumidity()

Returns the last humidity reading in percentage (%RH).
	•	Return Type: float
	•	Note: Call only after readData() returns true.

float hum = dht.getHumidity();

⸻

Notes
	•	Timing-sensitive: Uses delayMicroseconds() for signal timing.
	•	Non-blocking read not supported.
	•	Avoid using with other time-critical tasks.
	•	Compatible with AVR-based boards (e.g. Arduino Uno, Nano).

⸻
⸻

 License

This library is licensed under the MIT License.

MIT License

Copyright (c) 2025 Fadhil

Permission is hereby granted, free of charge, to any person obtaining a copy...
(full MIT text here)


⸻


