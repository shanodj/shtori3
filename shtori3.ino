#include <AccelStepper.h>

#include <AFMotor.h>
AF_Stepper motor1(48, 2);
AF_Stepper motor2(48, 1);
int button_1 = 14; //analog pin 0
int button_2 = 15; //analog pin 1
int val1 = LOW;
int val2 = LOW;
int speed = 15;
// you can change these to DOUBLE or INTERLEAVE or MICROSTEP!
// wrappers for the first motor!
void forwardstep1() {  
  motor1.onestep(FORWARD, DOUBLE);
}
void backwardstep1() {  
  motor1.onestep(BACKWARD, DOUBLE);
}
void forwardstep2() {  
  motor2.onestep(FORWARD, DOUBLE);
}
void backwardstep2() {  
  motor2.onestep(BACKWARD, DOUBLE);
}
// wrappers for the second motor!
//void forwardstep2() {  
//  motor2.onestep(FORWARD, DOUBLE);
//}
//void backwardstep2() {  
//  motor2.onestep(BACKWARD, DOUBLE);
//}
// Motor shield has two motor ports, now we'll wrap them in an AccelStepper object
AccelStepper stepper1(forwardstep1, backwardstep1);
AccelStepper stepper2(forwardstep2, backwardstep2);

void setup() {
  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);

  stepper1.setMaxSpeed(500.0);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(200.0);

  stepper2.setMaxSpeed(600.0);
  stepper2.setAcceleration(150.0);
  stepper2.setSpeed(100.0);
//  Serial.begin(9600);           // set up Serial library at 9600 bps
  
}

void loop() {
  val1 = digitalRead(button_1);
  val2 = digitalRead(button_2);
  // If a switch is pushed down (low), set the sign value appropriately
  if (val1 == 0) {
    stepper2.move(4800);
    }
  else if (val2 == 0) {    
    stepper2.move(-4800);
    }
  else if (val1 == 1 && val2 == 1) {
    stepper2.move(0);
  }
    stepper2.run();
}
