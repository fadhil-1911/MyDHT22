/**
 * @file    MyDHT22.h
 * @brief   Header file for MyDHT22 class to read data from DHT22 sensor.
 * @author  Fadhil
 * @version 1.0.2
 * @date    20 June 2025
 *
 * @details
 * This file declares the MyDHT22 class, a lightweight and efficient driver
 * for reading temperature and humidity from the DHT22 sensor using manual
 * bit-level timing (bit-banging).
 *
 * Designed for AVR-based Arduino boards such as UNO and Nano.
 */

#ifndef MYDHT22_H // Prevent multiple inclusion of the same header
#define MYDHT22_H

#include <Arduino.h> // Required for types like uint8_t and functions like pinMode()

// MyDHT22 class to interface with a DHT22 temperature and humidity sensor
class MyDHT22 {
  public:
    // Constructor: initialize the sensor with a specific digital pin
    MyDHT22(uint8_t pin);

    // Reads temperature and humidity from the sensor and stores in internal buffer
    bool readData();

    // Returns the last read humidity value in %RH
    float getHumidity();

    // Returns the last read temperature value in degrees Celsius
    float getTemperature();

  private:
    uint8_t _pin;     // Pin connected to DHT22 data line
    uint8_t data[5];  // Buffer to store 5 bytes of data from DHT22 (40 bits)
};

#endif // MYDHT22_H
