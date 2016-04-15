/*
Arduino library for KY-013 analog temperature sensor module
Copyright 2016 Paul Philippov, themactep@gmail.com
*/

#include "KY013.h"

KY013::KY013(uint8_t _pin) {
  pin = _pin;
  pinMode(pin, INPUT);
}

float KY013::readTemperatureK() {
  int rawADC = analogRead(pin);
  float r = Resistor / (1024.0 / rawADC - 1);
  float lnR = log(r);
  float temp = 1 / (Const_A + Const_B * lnR + Const_C * pow(lnR, 3));
  return temp;
}

float KY013::readTemperatureC() {
  float temp = readTemperatureK();
  return convertKelvinToCelsius(temp);
}

float KY013::readTemperatureF() {
  float temp = readTemperatureC();
  return convertCelsiusToFahrenheit(temp);
}

float KY013::convertKelvinToCelsius(float tempK) {
  return tempK - 273.15;
}

float KY013::convertCelsiusToFahrenheit(float tempC) {
  return (tempC * 9.0) / 5.0 + 32.0;
}
