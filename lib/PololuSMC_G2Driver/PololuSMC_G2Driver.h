#ifndef POLOLUSMCG2_DRIVER_h
#define POLOLUSMCG2_DRIVER_h

#include <cstdint>
#include <Wire.h>

class PololuSMC_G2Driver
{
private:
    TwoWire &wire;
    const uint8_t DeviceAdress;
    static const int16_t maxSpeed = 3200;
    static const int16_t minSpeed = -3200;

public:
    PololuSMC_G2Driver(TwoWire &_wire, const uint8_t _DeviceAdress)
        : wire(_wire),
          DeviceAdress(_DeviceAdress)
          
    {
    }

    void exitSafeStart()
    {
        wire.beginTransmission(DeviceAdress);
        wire.write(0x83); // Exit safe start
        wire.endTransmission();
    }

    void setSpeed(int16_t speed)
    {
        if (speed > maxSpeed)
            speed = maxSpeed;

        if (speed < minSpeed)
            speed = minSpeed;

        uint8_t cmd = 0x85; // Motor forward

        if (speed < 0)
        {
            cmd = 0x86; // Motor revers
            speed = -speed;
        }

        wire.beginTransmission(DeviceAdress);
        wire.write(cmd);
        wire.write(speed & 0x1F);
        wire.write(speed >> 5 & 0x7F);
        wire.endTransmission();
    }
};

#endif
