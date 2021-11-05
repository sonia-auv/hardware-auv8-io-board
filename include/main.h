#ifndef MAIN_H
#define MAIN_H

#include "rtos.h"
#include "mbed.h"
#include "pinDef.h"
#include "RS485/RS485.h"
#include "RS485/RS485_definition.h"


DigitalIn   KillSwitch(KILL_SWITCH);   

DigitalOut TorpedoPort(TORPEDO_PORT);
DigitalOut TorpedoStarboard(TORPEDO_STARBOARD);


DigitalOut DropperPort(DROPPER_PORT);
DigitalOut DropperStarboard(DROPPER_STARBOARD);

/**
DigitalIn LeakSensorBunker(LEAK_SENSOR_BUNKER);
DigitalIn LeakSensorGeneral(LEAK_SENSOR_GENERAL);
PwmOut Newton(PWM_NEWTON);
**/

#endif