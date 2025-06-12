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
```cpp

⸻

📘 API Documentation – MyDHT22 Library

Below is a concise explanation of the API (Application Programming Interface) provided by the MyDHT22 library:

⸻

🔧 Core Functions (MyDHT22.h)

⸻

📌 1. MyDHT22(uint8_t pin)
	•	Purpose: Constructor that sets the digital pin connected to the DHT22 sensor.
	•	Example:
```cpp
MyDHT22 dht(2);
```cpp


⸻

📌 2. bool read()
	•	Purpose: Reads temperature and humidity data from the sensor.
	•	Returns: true if successful, false if failed (e.g., timing issues).
	•	Note: Must be called before accessing temperature or humidity values.
	•	Example:
```cpp
if (dht.read()) {
  // Reading was successful
}
```cpp


⸻

📌 3. float getTemperature()
	•	Purpose: Returns the temperature value in degrees Celsius after a successful read().
	•	Example:
```cpp
Serial.println(dht.getTemperature());
```cpp


⸻

📌 4. float getHumidity()
	•	Purpose: Returns the relative humidity (%) after a successful read().
	•	Example:
```cpp
Serial.println(dht.getHumidity());
```cpp


⸻

📌 5. bool isValid()
	•	Purpose: Checks if the most recent reading is valid.
	•	Example:
```cpp
if (dht.isValid()) {
  // The data is valid and safe to use
}
```cpp


⸻

  