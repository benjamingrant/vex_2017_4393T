#include "main.h"
#include "drivetrain.h"
#include "lift.h"
#include "claw.h"

void operatorControl() {
  bool clawToggle = false; //needed to put this bool in a higher scope for the claw toggle
  while (1){
    drivetrain();
    lift();
    claw();
  }
}
