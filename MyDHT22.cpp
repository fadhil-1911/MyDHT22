#include "MyDHT22.h"

MyDHT22::MyDHT22(uint8_t pin) : _pin(pin), _temperature(0), _humidity(0) {
  pinMode(_pin, INPUT_PULLUP);
}

bool MyDHT22::read() {
  return readSensor();
}

float MyDHT22::getTemperature() {
  return _temperature;
}

float MyDHT22::getHumidity() {
  return _humidity;
}

bool MyDHT22::readSensor() {
  uint8_t data[5] = {0};
  uint8_t byteIdx = 0, bitIdx = 7;

  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delay(1);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(30);
  pinMode(_pin, INPUT_PULLUP);

  unsigned long start = micros();
  while (digitalRead(_pin) == HIGH) if (micros() - start > 100) return false;
  start = micros();
  while (digitalRead(_pin) == LOW) if (micros() - start > 100) return false;
  start = micros();
  while (digitalRead(_pin) == HIGH) if (micros() - start > 100) return false;

  for (int i = 0; i < 40; ++i) {
    while (digitalRead(_pin) == LOW);
    unsigned long t = micros();
    while (digitalRead(_pin) == HIGH);
    if ((micros() - t) > 40) data[byteIdx] |= (1 << bitIdx);
    if (bitIdx-- == 0) { bitIdx = 7; byteIdx++; }
  }

  uint8_t sum = data[0] + data[1] + data[2] + data[3];
  if (data[4] != sum) return false;

  _humidity = (data[0] << 8 | data[1]) * 0.1;
  int16_t tempRaw = (data[2] << 8 | data[3]);
  if (tempRaw & 0x8000) tempRaw = -(tempRaw & 0x7FFF);
  _temperature = tempRaw * 0.1;
  return true;
}
