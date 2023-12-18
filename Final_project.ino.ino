 
#include <ESP32Servo.h>
Servo leftServo;
Servo rightServo;
int8_t  rightServoPin = 1;
int8_t leftServoPin = 3;
int8_t position[]={90,180,-180};
int8_t signal_1 = 0;// the variable that controls index  of position.
int8_t signal_2 = 0;
int8_t physicalButtonForward = 41;
int8_t physicalButtonBackwards = 36;
int8_t physicalButtontleft = 42; 
int8_t physicalButtonRight = 39; 

 void IRAM_ATTR Forward()
 {
   signal_1 = 1;
   signal_2 = 1;
 }
 
 void IRAM_ATTR Backwards()
 {
  signal_1 = 2; 
  signal_2 = 2;
  
 }
 
 void IRAM_ATTR Left()
 {
  signal_1 = 2;
  
 }

 void IRAM_ATTR Right()
 {
  signal_2 = 2;

 }




void setup() {
	
  
  


 ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	rightServo.setPeriodHertz(50);    
	rightServo.attach(rightServoPin, 500, 2400); 
	leftServo.setPeriodHertz(50);    
	leftServo.attach(leftServoPin, 500, 2400);
 attachInterrupt(physicalButtonForward, Forward ,RISING);
attachInterrupt(physicalButtonBackwards, Backwards ,RISING);
attachInterrupt(physicalButtontleft, Left ,RISING);
attachInterrupt(physicalButtonRight, Right ,RISING);

}
void loop() 
{
 
    leftServo.write(signal_1);    
    rightServo.write(signal_2);

}


 