/***
 * 
 * Example code: This code is a simple program that turn on/off a LED with a button while another LED flash.
 * 
 ***/

#include "main.h"
#define COIL_ON_TIME 500
//RS485 declaration
RS485 rs(SLAVE_IO);

//Declaration of threads
Thread thDropperPORT;
Thread thDropperSTARBOARD;

Thread thTorpedoPORT;
Thread thTorpedoSTARBOARD;




DigitalOut * findPinTorpedo(uint8_t data){

  DigitalOut *pin=NULL;

  switch (data)
  {
  case DATA_IO_TORPEDO_PORT:
    pin = &TorpedoStarboard;
    break;
  
  case DATA_IO_TORPEDO_STARBOARD:
    pin = &TorpedoPort;
    break;
  
  default:
    pin=NULL;
    break;
  }

  return pin;
}

DigitalOut * findPinDropper(uint8_t data){

  DigitalOut *pin=NULL;

  switch (data)
  {
  case DATA_IO_DROPPER_STARBOARD:
    pin = &DropperStarboard;
    break;
  
  case DATA_IO_DROPPER_PORT:
    pin = &DropperPort;
    break;
  
  default:
    pin=NULL;
    break;
  }

  return pin;
}

void threadDropperSTARBOARD()
{
  uint8_t cmd_array[1] = {CMD_IO_DROPPER_ACTION};
  uint8_t buffer_receive[255];
  DigitalOut *pin=NULL;
  //Declaration, only put one command per thread
  while(1)
  {
    if(rs.read(cmd_array,1,buffer_receive)){      

      pin = findPinDropper(buffer_receive[0]);

      if(KillSwitch == 0 && pin != NULL){
          (*pin) = 1;
          rs.write(SLAVE_IO,CMD_IO_DROPPER_ACTION,1, &(buffer_receive[0]));
          ThisThread::sleep_for(COIL_ON_TIME);
          (*pin) = 0;
      }

  }
    
  }
}

void threadTorpedoSTARBOARD()
{
  uint8_t cmd_array[1] = {CMD_IO_TORPEDO_ACTION};
  uint8_t buffer_receive[255];
  DigitalOut *pin=NULL;
  //Declaration, only put one command per thread
  while(1)
  {
    if(rs.read(cmd_array,1,buffer_receive)){      

      pin = findPinTorpedo(buffer_receive[0]);

      if(KillSwitch == 0 && pin != NULL){
          (*pin) = 1;
          rs.write(SLAVE_IO,CMD_IO_TORPEDO_ACTION,1, &(buffer_receive[0]));
          ThisThread::sleep_for(COIL_ON_TIME);
          (*pin) = 0;
      }

  }
    
  }
}
 
int main()
{

  DropperPort = 0;
  DropperStarboard = 0;

  TorpedoPort = 0;
  TorpedoStarboard = 0;



  //Declaration of all the thread (linked to one function)
  //thDropperPORT.start(threadDropperPORT);
  //thDropperPORT.set_priority(osPriorityHigh);

  thDropperSTARBOARD.start(threadDropperSTARBOARD);
  thDropperSTARBOARD.set_priority(osPriorityHigh);

  //thTorpedoPORT.start(threadTorpedoPORT);
  //thTorpedoPORT.set_priority(osPriorityHigh);

  thTorpedoSTARBOARD.start(threadTorpedoSTARBOARD);
  thTorpedoSTARBOARD.set_priority(osPriorityHigh);
}