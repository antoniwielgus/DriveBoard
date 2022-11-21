/**
 * @file communication.h
 * @author Antoni Wielgus
 * @date 06.11.2022
*/

//firstly you should initialize Serial2 object, (set rxPin, txPin and baudrate)

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <LowLevelImpl/StreamComm.h>
#include <DataPacket.h>
#include <SerialUART.h>
#include <cstdint>

union uint8_tToUint16_t
{
    uint8_t charArray[2];
    uint16_t mergedValue;
};


class Communication
{
private:
    static const uint8_t MaxBufferSize = 15;
    PacketComm::StreamComm <MaxBufferSize> streamComm;

    uint16_t LFW; //left front wheel
    uint16_t RFW; //right front wheel
    uint16_t LMW; //left middle wheel
    uint16_t RMW; //right middle wheel
    uint16_t LRW; //left rear wheel
    uint16_t RRW; //right rear wheel

    uint16_t missedPackets = 0;
    uint8_tToUint16_t conversion;


public:
    Communication(HardwareSerial* _serial);
    void receiveAndMergeBytes();


    //this function return value between -3200 and 3200
    uint16_t getLFWspeed();
    uint16_t getRFWspeed();
    uint16_t getLMWspeed();
    uint16_t getRMWspeed();
    uint16_t getLRWspeed();
    uint16_t getRRWspeed();

    uint16_t getMissedPacket();
};

#endif

