#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);



void setup() {
Serial.begin(9600);


motor1.run(RELEASE);
motor1.setSpeed(255);
motor2.run(RELEASE);
motor2.setSpeed(255);
motor3.run(RELEASE);
motor3.setSpeed(255);
motor4.run(RELEASE);
motor4.setSpeed(255);
}

void loop() {

//  if(Serial.available()>0)
//    {     
//       char command= Serial.read(); // reading the data received from the bluetooth module
//       stand();
//       switch(command)
//       {
//         case 'F': {forward(); break;}  // when a is pressed on the app on your smart phone
//         case 'B': {backward(); break;}
//         case 'L': {left(); break;}
//         case 'R': {right();  break;}                   
//         default : break;
//       }
//       Serial.println(command);
//    }
 forward();

}

void forward() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void backward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void left() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void right() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void stand() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
