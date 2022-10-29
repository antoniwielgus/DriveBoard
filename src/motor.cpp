/**
 * @file motor.cpp
 * @author Antoni Wielgus
 * @date 28.10.2022
 */

#include "motor.h"

void Motor::exitSafeStart(uint8_t smcDeviceNumber)
{
    Wire.beginTransmission(smcDeviceNumber);
    Wire.write(0x83); // Exit safe start
    Wire.endTransmission();
}

Motor::Motor(const uint8_t _smcDeviceNumber, const int16_t _maxSpeed, const int16_t _minSpeed, const uint8_t _SDAPin, const uint8_t _SCLPin) : smcDeviceNumber(_smcDeviceNumber), maxSpeed(_maxSpeed), minSpeed(_minSpeed), SDAPin(_SDAPin), SCLPin(_SCLPin)
{
    Wire.setSDA(SDAPin);
    Wire.setSCL(SCLPin);
    Wire.begin();
}

void Motor::setMotorSpeed(uint8_t smcDeviceNumber, int16_t speed)
{
    uint8_t cmd = 0x85; // Motor forward
    if (speed < 0)
    {
        cmd = 0x86; // Motor revers
        speed = -speed;
    }
    Wire.beginTransmission(smcDeviceNumber);
    Wire.write(cmd);
    Wire.write(speed & 0x1F);
    Wire.write(speed >> 5 & 0x7F);
    Wire.endTransmission();
}

// void Motor::slowAcceleration(const uint8_t motorNumber, uint8_t arrayIndex)
// {

// }
