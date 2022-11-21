/**
 * @file setupRover.h
 * @author Antoni Wielgus
 * @date 15.11.2022
*/

#ifndef SETUPROVER_H
#define SETUPROVER_H

#include <Wire.h>
#include "motor.h"
#include "communication.h"
#include <Tasker.h>

extern Tasker tasker;

extern PololuSMC_G2Driver driverLF;
extern PololuSMC_G2Driver driverRF;
extern PololuSMC_G2Driver driverLM;
extern PololuSMC_G2Driver driverRM;
extern PololuSMC_G2Driver driverLB;
extern PololuSMC_G2Driver driverRB;

extern Motor motorLF;
extern Motor motorRF;
extern Motor motorLM;
extern Motor motorRM;
extern Motor motorLB;
extern Motor motorRB;

extern Communication communication;

void setupCommunication();

#endif

