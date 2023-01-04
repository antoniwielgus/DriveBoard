/**
 * @file setupRover.cpp
 * @author Antoni Wielgus
 * @date 15.11.2022
*/

#include "setupRover.h"

const int maxTasksAmount = 5;
Tasker tasker(maxTasksAmount);

const uint8_t ledPin = 25;

const uint8_t SCL_pin = 3;
const uint8_t SDA_pin = 2;
const uint8_t RX_pin = 5;
const uint8_t TX_pin = 4;
const uint32_t DriveSerialBaudrate = 115200;
const uint32_t SerialBaudrate = 115200;

const uint8_t deviceAdress1 = 0x01;
const uint8_t deviceAdress2 = 0x02;
const uint8_t deviceAdress3 = 0x03;
const uint8_t deviceAdress4 = 0x04;
const uint8_t deviceAdress5 = 0x05;
const uint8_t deviceAdress6 = 0x06;

PololuSMC_G2Driver driverLF(Wire1, deviceAdress1);
PololuSMC_G2Driver driverRF(Wire1, deviceAdress2);
PololuSMC_G2Driver driverLM(Wire1, deviceAdress3);
PololuSMC_G2Driver driverRM(Wire1, deviceAdress4);
PololuSMC_G2Driver driverLB(Wire1, deviceAdress5);
PololuSMC_G2Driver driverRB(Wire1, deviceAdress6);

Motor motorLF(driverLF);
Motor motorRF(driverRF);
Motor motorLM(driverLM);
Motor motorRM(driverRM);
Motor motorLB(driverLB);
Motor motorRB(driverRB);

Communication communication(&Serial2);

class : public IExecutable
{
    void execute() override
    {
        communication.receiveAndMergeBytes();

        //Serial.println(communication.getLFWspeed());

        
    }
} receiveFrameTask;

class : public IExecutable
{
    void execute() override
    {
        if (Serial2.available())
            digitalWrite(ledPin, HIGH);
        else
            digitalWrite(ledPin, LOW);
    }
} bliningLedTask;

class : public IExecutable
{
    void execute() override
    {
        motorLF.setSpeed(communication.getLFWspeed());
    }
} driveTask;


//to do tasker

void setupCommunication()
{
    Wire1.setSCL(SCL_pin);
    Wire1.setSDA(SDA_pin);
    Wire1.begin();

    Serial2.setRX(RX_pin);
    Serial2.setTX(TX_pin);
    Serial2.begin(DriveSerialBaudrate);

    Serial.begin(SerialBaudrate);

    pinMode(ledPin, OUTPUT);

    tasker.addTask_Hz(&receiveFrameTask, 100.f);    
    tasker.addTask_Hz(&bliningLedTask, 1.f);
    tasker.addTask_Hz(&driveTask, 100.f);
}

