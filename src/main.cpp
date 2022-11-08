#include <Arduino.h>
#include <Wire.h>
#include "motor.h"

const int led = 25;

PololuSMC_G2Driver driver1(Wire1, 1);
Motor motor1(driver1);

void setup()
{
  pinMode(led, OUTPUT);

  Wire1.setSCL(3);
  Wire1.setSDA(2);
  Wire1.begin();
}

void loop()
{

}