/**
 * @file receiveFrame.cpp
 * @author Antoni Wieglgus
 * @date 08.10.2022
*/

#include "receiveFrame.h"

receiveFrame::receiveFrame(uint8_t rxPin, uint8_t txPin, uint16_t serialBaudrate)
{
    this->rxPin = rxPin;
    this->txPin = txPin;
    this->serialBaudrate = serialBaudrate;

    
}
