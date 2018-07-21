#include <KY013.h>

#define PIN A0

KY013 thermistor(PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = thermistor.readTemperatureC();
  Serial.print(temp);
  Serial.println("C");
  delay(1000);
}
