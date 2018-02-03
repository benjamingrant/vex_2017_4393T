#include "main.h"
#include "claw.h"

void setclaw(bool open, bool close){
  if(open == true && close == false){
    motorSet(9, 127);
  }
  else if(open == false && close == true){
    motorSet(9, -127);
  }
  else{
    motorStop(9);
  }
}

void claw(){
  bool open = joystickGetDigital(1, 7, JOY_UP);
  bool close = joystickGetDigital(1, 7, JOY_DOWN);
  setclaw(open, close);
}
