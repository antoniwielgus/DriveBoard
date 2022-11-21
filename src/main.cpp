#include <Arduino.h>
#include "setupRover.h"

uint8_t array[12];

union convertNumber
{
  uint8_t values[2];
  uint16_t merged;
} myUnion;

// #include <Wire.h>
// #include "motor.h"
// #include "communication.h"

// const int led = 25;

// PololuSMC_G2Driver driver1(Wire1, 1);
// Motor motor1(driver1);
// Communication communicateWithRover;

// uint16_t speed = 0;

void setup()
{
  // pinMode(led, OUTPUT);

  // Wire1.setSCL(3);
  // Wire1.setSDA(2);
  // Wire1.begin();

  // Serial2.setRX(5);
  // Serial2.setTX(4);
  // Serial2.begin(9600);

  // Serial.begin(115200);

  for (int i = 0; i < 12; i++)
    array[i] = 0;

  setupCommunication();
}

void loop()
{
  tasker.loop();

  // if (Serial2.available() > 0)
  //   Serial2.readBytes(array, 12);

  
  // myUnion.values[0] = array[0];
  // myUnion.values[1] = array[1];

  // for (int i = 0; i < 12; ++i)
  // {
  //   Serial.print(array[0]);
  //   Serial.print(" ");
  // }

  // Serial.println();
}

