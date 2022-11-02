/**
 * @file motor.h
 * @author Antoni Wielgus
 * @date 28.10.2022
*/

#ifndef MOTOR
#define MOTOR

#include <Arduino.h>
#include <Wire.h>

class Motor
{
private:
    TwoWire& myWire;
    const uint8_t smcDeviceNumber = 1;
    const int16_t maxSpeed = 2;
    const int16_t minSpeed = 2;

public:
    void exitSafeStart();
    Motor(TwoWire& _myWire ,const uint8_t _smcDeviceNumber, const int16_t _maxSpeed, const int16_t _minSpeed);
    void setMotorSpeed(int16_t speed);
    void blinkLed(uint8_t ledPin);
};

#endif

