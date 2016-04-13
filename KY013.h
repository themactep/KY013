/*
Arduino library for KY-013 analog temperature sensor module
Copyright 2016 Paul Philippov, themactep@gmail.com
*/

#ifndef KY013_H
#define KY013_H

#include "Arduino.h"

// for 10k balance resistor
#define Resistor  10000.0
#define Const_A  0.001129148
#define Const_B  0.000234125
#define Const_C  0.0000000876741

class KY013 {
public:
  KY013(uint8_t pin);
  float readTemperatureK();
  float readTemperatureC();
  float readTemperatureF();

private:
  uint8_t pin;
  float convertKelvinToCelsius(float temp);
  float convertCelsiusToFahrenheit(float temp);
};

#endif
