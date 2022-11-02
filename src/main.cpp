#include <Arduino.h>
#include <Wire.h>
#include "motor.h"

const int led = 25;

Motor firstMotor(Wire1, 1, 3200, -3200);

void setup()
{
  pinMode(led, OUTPUT);

  Wire1.setSCL(3);
  Wire1.setSDA(2);
  Wire1.begin();

  firstMotor.exitSafeStart();
}

void loop()
{
  firstMotor.setMotorSpeed(200);
}