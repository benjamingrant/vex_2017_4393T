#include "main.h"
#include "claw.h"

void setclaw(bool open, bool close){
  if(open && !close){
    motorSet(9, 127);
  }
  else if(close && !open){
    motorSet(9, -127);
  }
  else{
    motorSet(9, 0);
  }
}

void claw(){
  bool close = joystickGetDigital(1, 5, JOY_UP);
  bool open = joystickGetDigital(1, 5, JOY_DOWN);
  setclaw(open, close);
}
