/**
 * @file    MyDHT22.cpp
 * @brief   Implementation of the MyDHT22 sensor library for DHT22 (AM2302).
 * @author  Fadhil
 * @version 1.0.2
 * @date    20 Jun 2025
 *
 * @details
 * This library provides manual bit-level communication with the DHT22
 * temperature and humidity sensor without using delay-heavy libraries.
 * It is optimized for AVR-based boards (like Arduino UNO, Nano) and provides:
 *   - Manual start signal
 *   - Bit-banging logic to read 40 bits of data
 *   - Checksum validation
 *   - Accurate parsing of temperature and humidity values
 *
 * Usage:
 *    MyDHT22 dht(7);
 *    if (dht.readData()) {
 *        float temp = dht.getTemperature();
 *        float hum = dht.getHumidity();
 *    }
 *
 * This file is part of the MyDHT22 library.
 */

#include "MyDHT22.h" // Include the custom header for DHT22 sensor class

// Constructor: stores the pin number and configures it as input with pull-up
MyDHT22::MyDHT22(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
}

bool MyDHT22::readData() {
  uint8_t byteIdx = 0, bitIdx = 7; // Index for storing bits into data bytes
  uint32_t t; // For timing measurement (microseconds)

  // Clear previous data (5 bytes = 40 bits)
  for (uint8_t i = 0; i < 5; i++) data[i] = 0;

  // ==== Send start signal to DHT22 ====
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);      // Pull line LOW to initiate communication
  delay(1);                     // Hold LOW for at least 1ms (DHT22 requirement)
  digitalWrite(_pin, HIGH);     // Pull line HIGH
  delayMicroseconds(30);        // Short delay before releasing line
  pinMode(_pin, INPUT);         // Set pin to input for sensor response

  // ==== Wait for DHT22 response ====
  // DHT22 responds with: LOW 80us → HIGH 80us → start sending data

  // Wait for initial LOW (response start)
  t = micros();
  while (digitalRead(_pin) == HIGH)
    if ((micros() - t) > 90) return false; // timeout if no response

  // Wait for HIGH period
  t = micros();
  while (digitalRead(_pin) == LOW)
    if ((micros() - t) > 90) return false; // timeout if signal incorrect

  // Wait for second LOW before data transmission
  t = micros();
  while (digitalRead(_pin) == HIGH)
    if ((micros() - t) > 90) return false; // timeout if signal incorrect

  // ==== Read 40 bits (5 bytes) from sensor ====
  for (uint8_t i = 0; i < 40; i++) {
    // Wait for pin to go HIGH (start of bit)
    while (digitalRead(_pin) == LOW);

    // Measure how long pin stays HIGH
    t = micros();
    while (digitalRead(_pin) == HIGH);

    // If HIGH lasts more than ~40us, it's a '1', else it's a '0'
    if ((micros() - t) > 40) data[byteIdx] |= (1 << bitIdx);

    // Move to next bit position
    if (bitIdx == 0) {
      bitIdx = 7;
      byteIdx++;
    } else {
      bitIdx--;
    }
  }

  // ==== Verify checksum ====
  // Checksum = sum of first 4 bytes must equal 5th byte
  uint8_t chk = data[0] + data[1] + data[2] + data[3];
  return (chk == data[4]);
}

float MyDHT22::getHumidity() {
  // Combine data[0] and data[1] to form 16-bit humidity value
  // Multiply by 0.1 to convert to percent (%RH)
  return ((data[0] << 8) | data[1]) * 0.1;
}

float MyDHT22::getTemperature() {
  // Combine data[2] and data[3], masking bit 15 (sign bit)
  int16_t raw = ((data[2] & 0x7F) << 8) | data[3];
  float t = raw * 0.1;

  // If bit 7 in data[2] is set, temperature is negative
  if (data[2] & 0x80) t = -t;

  return t;
}