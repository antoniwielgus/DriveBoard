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
    const uint8_t smcDeviceNumber;
    const int16_t maxSpeed;
    const int16_t minSpeed;
    const uint8_t SDAPin;
    const uint8_t SCLPin;

    void exitSafeStart(uint8_t smcDeviceNumber);

public:
    Motor(const uint8_t _smcDeviceNumber, const int16_t _maxSpeed, const int16_t _minSpeed, const uint8_t _SDAPin, const uint8_t _SCLPin);

    void setMotorSpeed(uint8_t smcDeviceNumber, int16_t speed);
    // void slowAcceleration(const uint8_t motorNumber, uint8_t arrayIndex);

};

#endif
