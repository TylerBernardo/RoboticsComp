int firstRun = 0;

void armTurn(){
  armMotorLeft.setVelocity(35 , percent);
  armMotorRight.setVelocity(35 , percent);
  double average = (armMotorLeft.current(amp) + armMotorRight.current(amp))/2
  if(average > limit){
    armMotorLeft.setVelocity(70 , percent);
    armMotorRight.setVelocity(70, percent);
  }
  armMotorLeft.spin(forward);
  armMotorRight.spin(forward);
  if(firstrun = 0){
    firstRun = 1;
    double limit = (armMotorLeft.current(amp) + armMotorRight.current(amp))/2
  }
}
