#include "main.h"

void moveDrivetrain(int leftSpeed, int rightSpeed){

  motorSet(3, leftSpeed) ; // back left wheel moves
  motorSet(3, leftSpeed) ; // front left wheel moves

  motorSet(2, rightSpeed) ; // back right wheel moves
  motorSet(2, rightSpeed) ; // front right wheel moves

}

void moveLift(int liftSpeed){

  motorSet(8, liftSpeed) ; // left lift motor moves up or down
  motorSet(9, liftSpeed) ; // right lift motor moves up or down

}

void operatorControl() {

  int driveDirection = -1;//1 for lift facing forward; -1 for backward...

  while (1){

    bool rightDpadUp = joystickGetDigital(1, 8, JOY_UP); //up button on right dpad, dude
    if(rightDpadUp){
      driveDirection *= -1; //negate driveDirection variable
    }


    int leftStickState = joystickGetAnalog(1, 4/*3*/); //left stick forward/back (-127 to +127)
    int rightStickState = joystickGetAnalog(1, 1/*2*/); //right stick forward/back (-127 to +127)

    moveDrivetrain(driveDirection*leftStickState, driveDirection*rightStickState);//driving with negation toggle


    bool rightTriggerTopState = joystickGetDigital(1, 5, JOY_UP); //is top right trigger pressed?
    bool rightTriggerBottomState = joystickGetDigital(1, 6, JOY_DOWN); //is bottom right trigger pressed?

    if(rightTriggerTopState){
      moveLift(127);
    } else if (rightTriggerBottomState){
      moveLift(-127);
    } else {
      moveLift(0);
    }


      delay(20);
  }
}
