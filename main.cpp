/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Clawbot Competition Template                              */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 10, D        
// ClawMotor            motor         3               
// ArmMotor             motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void){
 
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
   armMotorLeft.resetRotation();
  armMotorRight.resetRotation();
  //may use rotateTo() for intake, more exact and wont depend on its postion at start of code
  PickupMotorLeft.resetRotation();
  PickupMotorRight.resetRotation();
  Controller1.ButtonX.pressed(speedToggle); 
  Controller1.ButtonB.pressed(intakeReset);
  
  while(1 == 1){

    if(Controller1.Axis2.value() != 0 ){  //DRIVE FORWARD/BACKWARDS
          // normal mode
        double power  = Controller1.Axis2.value() * .75;
      if(x == 1){
        power = .25 * power; 
      }
      RightMotor.spin(directionType::fwd, power , velocityUnits::pct);
      RightMotor2.spin(directionType::fwd, power , velocityUnits::pct);
      LeftMotor.spin(directionType::fwd, power , velocityUnits::pct);
      LeftMotor2.spin(directionType::fwd, power , velocityUnits::pct);
    }else {

    }

    if( Controller1.Axis1.value() != 20){ // STRAFING
      int power = Controller1.Axis1.value() * .75;
      LeftMotor.spin(directionType::fwd, -power , velocityUnits::pct);
      LeftMotor2.spin(directionType::fwd, power , velocityUnits::pct);
      RightMotor.spin(directionType::fwd, power , velocityUnits::pct);
      RightMotor2.spin(directionType::fwd, -power , velocityUnits::pct);
    }else{
      
    }

    if(Controller1.Axis4.value() > 10){ //IN PLACE TURNING 
      int power = Controller1.Axis1.value() * .75;
      LeftMotor.spin(directionType::fwd,power, velocityUnits::pct);
      LeftMotor2.spin(directionType::fwd,power, velocityUnits::pct);
      RightMotor.spin(directionType::fwd,-power, velocityUnits::pct);
      RightMotor2.spin(directionType::fwd,-power, velocityUnits::pct);
    }else{
      
    }

    if(Controller1.ButtonL1.pressing() != 0){ //INTAKE
      PickupMotorLeft.spin(directionType::fwd, 127, velocityUnits::pct);
    PickupMotorRight.spin(directionType::fwd, 127, velocityUnits::pct);
    }else{
      PickupMotorLeft.spin(directionType::fwd, 0 , velocityUnits::pct);
  PickupMotorRight.spin(directionType::fwd, 0, velocityUnits::pct);
    }

    if(Controller1.ButtonR1.pressing() != 0){ //MOVE ARM UP
      double mPower = -2.5;
      int currentRotation = armMotorLeft.rotation(rotationUnits::deg);
      int rate = currentRotation / 10;
      int Power = mPower - rate;

      armMotorLeft.spin(directionType::fwd, Power , velocityUnits::pct);
      armMotorRight.spin(directionType::fwd, Power , velocityUnits::pct);
    }else{
      armMotorLeft.resetRotation();
      armMotorRight.resetRotation();
    }
    
    if(Controller1.ButtonR2.pressing() != 0){ //MOVE ARM DOWN
      double mPower = 2.5;
      int currentRotation = armMotorLeft.rotation(rotationUnits::deg);
      int rate = currentRotation / 10;
      int Power = mPower - rate;
      armMotorLeft.spin(directionType::fwd, -Power , velocityUnits::pct);
      armMotorRight.spin(directionType::fwd, -Power, velocityUnits::pct);
    }else{
      armMotorLeft.resetRotation();
      armMotorRight.resetRotation();
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.

  while (true) {
    wait(100, msec);
  }
}
