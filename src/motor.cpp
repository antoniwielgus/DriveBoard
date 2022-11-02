/**
 * @file motor.cpp
 * @author Antoni Wielgus
 * @date 28.10.2022
 */

#include "motor.h"

void Motor::exitSafeStart()
{
    myWire.beginTransmission(smcDeviceNumber);
    myWire.write(0x83); // Exit safe start
    myWire.endTransmission();
}

Motor::Motor(TwoWire& _myWire ,const uint8_t _smcDeviceNumber, const int16_t _maxSpeed, const int16_t _minSpeed) : myWire(_myWire) ,smcDeviceNumber(_smcDeviceNumber), maxSpeed(_maxSpeed), minSpeed(_minSpeed)
{}

void Motor::setMotorSpeed(int16_t speed)
{
    if (speed > maxSpeed || speed < minSpeed)
        return;

    uint8_t cmd = 0x85; // Motor forward
    if (speed < 0)
    {
        cmd = 0x86; // Motor revers
        speed = -speed;
    }
    myWire.beginTransmission(smcDeviceNumber);
    myWire.write(cmd);
    myWire.write(speed & 0x1F);
    myWire.write(speed >> 5 & 0x7F);
    myWire.endTransmission();
}

