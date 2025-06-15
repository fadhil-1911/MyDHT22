
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

## ⚙️ Installation Instructions
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

MyDHT22 dht(2); // Connect DHT22 to digital pin 2

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (dht.read()) {
    Serial.print("Temp: ");
    Serial.print(dht.getTemperature());
    Serial.print(" °C, Humidity: ");
    Serial.println(dht.getHumidity());
  }
  delay(2000);
}


⸻

 API Reference – MyDHT22

🔧 Core Functions (MyDHT22.h)

MyDHT22(uint8_t pin)
	•	Purpose: Constructor to initialize the sensor pin.
	•	Example: MyDHT22 dht(2);

⸻

bool read()
	•	Purpose: Read temperature & humidity data.
	•	Returns: true if successful, false otherwise.
	•	Note: Must be called before accessing temperature or humidity.
	•	Example:

if (dht.read()) {
  // Success
}



⸻

float getTemperature()
	•	Purpose: Returns the temperature in °C after successful read().
	•	Example: Serial.println(dht.getTemperature());

⸻

float getHumidity()
	•	Purpose: Returns the relative humidity (%) after successful read().
	•	Example: Serial.println(dht.getHumidity());

⸻

bool isValid()
	•	Purpose: Checks if the most recent reading is valid.
	•	Example:

if (dht.isValid()) {
  // Safe to use
}


⸻

 License

This library is licensed under the MIT License.

MIT License

Copyright (c) 2025 Fadhil

Permission is hereby granted, free of charge, to any person obtaining a copy...
(full MIT text here)


⸻


