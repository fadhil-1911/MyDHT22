#include "MyDHT22.h"

MyDHT22::MyDHT22(uint8_t pin) : _pin(pin), _temperature(0), _humidity(0) {
  pinMode(_pin, INPUT);
}

bool MyDHT22::read() {
  // Simulasi data bacaan. Gantikan dengan kod sebenar jika perlu
  _temperature = 25.0 + random(-10, 10) * 0.1;
  _humidity = 50.0 + random(-20, 20) * 0.1;
  return true;
}

float MyDHT22::getTemperature() {
  return _temperature;
}

float MyDHT22::getHumidity() {
  return _humidity;
}
