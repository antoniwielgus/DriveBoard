/**
 * @file receiveFrame.h
 * @author Antoni Wielgus
 * @date 08.10.2022
*/

#ifndef RECEIVE_FRAME
#define RECEIVE_FRAME

#include <Arduino.h>
#include <HardwareSerial.h>
// #include <uart.h>

class receiveFrame
{
private:
    uint8_t rxPin;
    uint8_t txPin;
    uint16_t serialBaudrate;

    static const uint8_t frameSize = 12;

    uint8_t driveFrame[frameSize];

public:
    receiveFrame(uint8_t rxPin, uint8_t txPin, uint16_t serialBaudrate);

    uint8_t getDriveFrameSize();
    uint8_t getRxPin();
    uint8_t getTxPin();
    uint8_t getValueFromDriveFrame(uint8_t number);
    
    void receiveNewFrame();
};


#endif