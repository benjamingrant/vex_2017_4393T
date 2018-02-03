#include "main.h"
#include "drivetrain.h"
#include "lift.h"
#include "claw.h"

void operatorControl() {
  while (1){
    drivetrain();
    lift();
    claw();
  }
}
