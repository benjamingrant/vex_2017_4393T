#include "main.h"
#include "drivetrain.h"

void setdrivetrain(int left, int right) {
  motorSet(3, left);
  motorSet(2, -right);
}

void drivetrain(){
  // handle the drivetrain
  int right = joystickGetAnalog(1, 2); // vertical axis on right joystick
  int left = joystickGetAnalog(1, 3); // vertical axis on left joystick
  setdrivetrain(left, right);
}
