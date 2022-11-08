/**
 * @file communication.h
 * @author Antoni Wielgus
 * @date 06.11.2022
*/

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <LowLevelImpl/StreamComm.h>
//#include <HardwareSerial.h>
#include <cstdint>
#include <SerialUART.h>

//using namespace PacketComm;

class Communication
{
private:
    static const uint8_t MaxBufferSize = 13;

    uint8_t rxPin;
    uint8_t txPin;
    uint16_t serialBaudrate;


public:
    Communication(uint8_t _rxPin, uint8_t _txPin, uint16_t _serialBaudrate);

};

#endif