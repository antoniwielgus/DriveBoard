/**
 * @file motor.h
 * @author Antoni Wielgus
 * @date 28.10.2022
*/

#ifndef MOTOR
#define MOTOR

#include <cstdint>
#include <PololuSMC_G2Driver.h>

class Motor
{
private:
    PololuSMC_G2Driver& driver;

public:
    Motor(PololuSMC_G2Driver& _driver) 
        : driver(_driver)
    {}

    void setSpeed(int16_t speed)
    {
        driver.setSpeed(speed);
    }

    void exitSafeStart()
    {
        driver.exitSafeStart();
    }

};

#endif

