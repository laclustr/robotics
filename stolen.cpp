#pragma region VEXcode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START V5 MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END V5 MACROS


// Robot configuration code.
motor fl = motor(PORT1, ratio18_1, false);

motor fr = motor(PORT2, ratio18_1, true);

motor bl = motor(PORT3, ratio18_1, false);

motor br = motor(PORT4, ratio18_1, true);

motor slip = motor(PORT5, ratio36_1, false);



// generating and setting random seed
void initializeRandomSeed(){
  int systemTime = Brain.Timer.systemHighResolution();
  double batteryCurrent = Brain.Battery.current();
  double batteryVoltage = Brain.Battery.voltage(voltageUnits::mV);

  // Combine these values into a single integer
  int seed = int(batteryVoltage + batteryCurrent * 100) + systemTime;

  // Set the seed
  srand(seed);
}



void vexcodeInit() {

  //Initializing random seed.
  initializeRandomSeed(); 
}


// Helper to make playing sounds from the V5 in VEXcode easier and
// keeps the code cleaner by making it clear what is happening.
void playVexcodeSound(const char *soundName) {
  printf("VEXPlaySound:%s\n", soundName);
  wait(5, msec);
}

#pragma endregion VEXcode Generated Robot Configuration

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// Include the V5 Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

int main() {
  //Code to win goes here, Luke typed this -> I smell
  fl.setVelocity(100, percent);
  fr.setVelocity(100, percent);
  bl.setVelocity(100, percent);
  br.setVelocity(100, percent);
  slip.setVelocity(100, percent);
  slip.spin(forward);
  for(int i = 0; i < 10; i++) {
    fl.spin(forward);
    fr.spin(forward);
    bl.spin(forward);
    br.spin(forward);
    wait(4, seconds);
    fl.spin(reverse);
    fr.spin(reverse);
    bl.spin(reverse);
    br.spin(reverse);
    wait(0.5, seconds);
  }
}
