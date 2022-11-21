/**
 * @file communication.cpp
 * @author Antoni Wielgus
 * @date 06.11.2022
 */

#include "communication.h"

Communication::Communication(HardwareSerial* _serial) : streamComm(_serial)
{
}

void Communication::receiveAndMergeBytes()
{
    // Check if any data has been received.
    if (streamComm.receive())
    {
        PacketComm::DataBuffer receivedData = streamComm.getReceived();

        conversion.charArray[0] = receivedData.buffer[1];
        conversion.charArray[1] = receivedData.buffer[0];
        LFW = conversion.mergedValue;

        conversion.charArray[0] = receivedData.buffer[3];
        conversion.charArray[1] = receivedData.buffer[2];
        RFW = conversion.mergedValue;

        conversion.charArray[0] = receivedData.buffer[5];
        conversion.charArray[1] = receivedData.buffer[4];
        LMW = conversion.mergedValue;

        conversion.charArray[0] = receivedData.buffer[7];
        conversion.charArray[1] = receivedData.buffer[6];
        RMW = conversion.mergedValue;

        conversion.charArray[0] = receivedData.buffer[9];
        conversion.charArray[1] = receivedData.buffer[8];
        LRW = conversion.mergedValue;

        conversion.charArray[0] = receivedData.buffer[11];
        conversion.charArray[1] = receivedData.buffer[10];
        RRW = conversion.mergedValue;

        Serial.println(RRW);
    }
    else
        missedPackets++;
}

uint16_t Communication::getLFWspeed()
{
    return LFW - 3200;
}

uint16_t Communication::getRFWspeed()
{
    return RFW - 3200;
}

uint16_t Communication::getLMWspeed()
{
    return LMW - 3200;
}

uint16_t Communication::getRMWspeed()
{
    return RMW - 3200;
}

uint16_t Communication::getLRWspeed()
{
    return LRW - 3200;
}

uint16_t Communication::getRRWspeed()
{
    return RRW - 3200;
}

uint16_t Communication::getMissedPacket()
{
    return missedPackets;
}

