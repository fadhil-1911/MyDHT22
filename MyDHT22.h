#ifndef MYDHT22_H
#define MYDHT22_H

#include <Arduino.h>

class MyDHT22 {
  public:
    MyDHT22(uint8_t pin);
    bool read();
    float getTemperature();
    float getHumidity();

  private:
    uint8_t _pin;
    float _temperature;
    float _humidity;
};

#endif
