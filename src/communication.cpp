/**
 * @file communication.cpp
 * @author Antoni Wielgus
 * @date 06.11.2022
 */

#include "communication.h"

Communication::Communication(uint8_t _rxPin, uint8_t _txPin, uint16_t _serialBaudrate) : 
    rxPin(_rxPin), txPin(_txPin), serialBaudrate(_serialBaudrate)
{
    Serial2.setTX(txPin);
    Serial2.setRX(rxPin);
    Serial2.begin(serialBaudrate);

    //StreamComm <MaxBufferSize> StreamComm(&Serial2);
}