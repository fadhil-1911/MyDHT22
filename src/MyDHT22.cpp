#include "MyDHT22.h"

MyDHT22::MyDHT22(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
}

bool MyDHT22::readData() {
  uint8_t byteIdx = 0, bitIdx = 7;
  uint32_t t;

  for (uint8_t i = 0; i < 5; i++) data[i] = 0;

  // Minta data
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delay(1); // minimum 1ms untuk DHT22
  digitalWrite(_pin, HIGH);
  delayMicroseconds(30);
  pinMode(_pin, INPUT);

  // Tunggu respon DHT22: LOW 80us + HIGH 80us
  t = micros();
  while (digitalRead(_pin) == HIGH)
    if ((micros() - t) > 90) return false;

  t = micros();
  while (digitalRead(_pin) == LOW)
    if ((micros() - t) > 90) return false;

  t = micros();
  while (digitalRead(_pin) == HIGH)
    if ((micros() - t) > 90) return false;

  // Terima 40 bit (5 byte)
  for (uint8_t i = 0; i < 40; i++) {
    while (digitalRead(_pin) == LOW); // tunggu HIGH
    t = micros();
    while (digitalRead(_pin) == HIGH); // tunggu habis HIGH
    if ((micros() - t) > 40) data[byteIdx] |= (1 << bitIdx);
    if (bitIdx == 0) {
      bitIdx = 7;
      byteIdx++;
    } else {
      bitIdx--;
    }
  }

  // Semak checksum
  uint8_t chk = data[0] + data[1] + data[2] + data[3];
  return (chk == data[4]);
}

float MyDHT22::getHumidity() {
  return ((data[0] << 8) | data[1]) * 0.1;
}

float MyDHT22::getTemperature() {
  int16_t raw = ((data[2] & 0x7F) << 8) | data[3];
  float t = raw * 0.1;
  if (data[2] & 0x80) t = -t;
  return t;
}
