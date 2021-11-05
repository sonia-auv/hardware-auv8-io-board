#ifndef PIN_DEF_H
#define PIN_DEF_H

//###################################################
//              BOARD PIN DEFINITION
//###################################################

#define KILL_SWITCH         PB_0

#define DROPPER_PORT        PC_12
#define DROPPER_STARBOARD   PE_2

#define TORPEDO_PORT        PE_3
#define TORPEDO_STARBOARD   PE_4

#define UART_RX             PD_14
#define UART_TX             PD_15

#define I2C_SDA             PB_7
#define I2C_SCL             PB_8

#define PWM_NEWTON          PA_2

#define LEAK_SENSOR_BUNKER  PB_12
#define LEAK_SENSOR_GENERAL PB_13

//For futur use, TODO: rename for actual use
#define ADD_DEVICE_PWM      PA_1
#define ADD_DEVICE_1_12V    PC_10
#define ADD_DEVICE_2_12V    PC_11

//###################################################
//              RS485 PIN DEFINITION
//###################################################

#define RS485_RX_PIN PA_10
#define RS485_TX_PIN PA_9

#define RS485_TE_PIN PA_12
#define RS485_DE_PIN PA_11
#define RS485_RE_PIN PA_8

#endif