#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

#include <Servo.h>

Servo myservo1,myservo2;

void setup() {
Serial.begin(9600);
                                                                                                                                                    
myservo1.attach(3);
myservo2.attach(5);

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
  // put your main code here, to run repeatedly:

      unsigned int servopos = Serial.read();
      unsigned int servopos1 = Serial.read();
      unsigned int realservo = (servopos1*256)+servopos;

      if(realservo >= 1000 && realservo <1180){ int servo1 = realservo;
                                                servo1 = map(servo1,1000,1180,0,180);
                                                myservo1.write(servo1);
                                                Serial.println(servo1);
                                                delay(10);               } 
    if(realservo >= 2000 && realservo <2180){ int servo2 = realservo;
                                                servo2 = map(servo2,2000,2180,0,180);
                                                myservo2.write(servo2);
                                                Serial.println(servo2);
                                                delay(10);               } 
  
      
      char command= Serial.read(); // reading the data received from the bluetooth module
      stand();
      switch(command)
      {
        case 'F': forward(); ;break; // when a is pressed on the app on your smart phone
        case 'B': backward() ;break; 
        case 'L': left() ;break; 
        case 'R': right() ;break;                     
        default : break;
      }
      Serial.println(command);
      

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
