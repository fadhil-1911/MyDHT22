#include "MyDHT22.h"

MyDHT22::MyDHT22(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
}

bool MyDHT22::readData() {
  uint8_t lastState = HIGH;
  uint8_t counter = 0;
  uint8_t j = 0, i;

  for (i = 0; i < 5; i++) data[i] = 0;

  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delay(20);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(40);
  pinMode(_pin, INPUT);

  for (i = 0; i < 85; i++) {
    counter = 0;
    while (digitalRead(_pin) == lastState) {
      counter++;
      delayMicroseconds(1);
      if (counter == 255) break;
    }

    lastState = digitalRead(_pin);
    if (counter == 255) break;

    if ((i >= 4) && (i % 2 == 0)) {
      data[j / 8] <<= 1;
      if (counter > 40) data[j / 8] |= 1;
      j++;
    }
  }

  if (j >= 40) {
    uint8_t checksum = data[0] + data[1] + data[2] + data[3];
    return ((checksum & 0xFF) == data[4]);
  }

  return false;
}

float MyDHT22::getHumidity() {
  return ((data[0] << 8) + data[1]) * 0.1;
}

float MyDHT22::getTemperature() {
  float t = (((data[2] & 0x7F) << 8) + data[3]) * 0.1;
  if (data[2] & 0x80) t = -t;
  return t;
}
