#include "main.h"
#include "lift.h"

void setlift(bool up, bool down){
  if(up && !down){
    motorSet(4, 127) ; // left lift motor moves up
    motorSet(5, -127) ; // right lift motor moves up
  }
  else if(down && !up){
    motorSet(4, -127) ; // left lift motor moves up or down
    motorSet(5, 127) ; // right lift motor moves up or down
  }
  else{
    motorStop(4);
    motorStop(5);
  }
}

void lift(){
  bool up = joystickGetDigital(1, 6, JOY_UP); //is top right trigger pressed?
  bool down = joystickGetDigital(1, 6, JOY_DOWN); //is bottom right trigger pressed?

  setlift(up, down);
}
