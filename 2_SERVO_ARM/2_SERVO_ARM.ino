#include <Servo.h>

Servo myservo1,myservo2;
void setup() {
  // put your setup code here, to run once:
myservo1.attach(3);
myservo2.attach(5);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>2)
{
  unsigned int servopos = Serial.read();
  unsigned int servopos1 = Serial.read();
  unsigned int realservo = (servopos1*256)+servopos;

  if(realservo >= 1000 && realservo <1180){ int servo1 = realservo;
                                             servo1 = map(servo1,1000,1180,0,180);
                                             myservo1.write(servo1);
                                             Serial.println(realservo);
                                             delay(10);               } 
 if(realservo >= 2000 && realservo <2180){ int servo2 = realservo;
                                             servo2 = map(servo2,2000,2180,0,180);
                                             myservo2.write(servo2);
                                             Serial.println(realservo);
                                             delay(10);               } 

                                            }
}

