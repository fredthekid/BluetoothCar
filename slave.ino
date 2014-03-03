#include <SoftwareSerial.h>
SoftwareSerial mySerial (5, 6);

const int front_LED [2] = {7, 8};
const int back_LED [2] = {12, 13};
const int buzzerPin = 3;

void setup(){
   mySerial.begin(9600);
   Serial.begin(115200);
   
   pinMode(3, OUTPUT); //buzzer
   pinMode(7,OUTPUT); //front led
   pinMode(8,OUTPUT); //front led
   pinMode(9,OUTPUT); //speed motor
   pinMode(10,OUTPUT); //speed motor
   pintMode(11,OUTPUT); //steering servo
   pinMode(12,OUTPUT); //back led
   pinMode(13,OUTPUT); //back led
   
   //TCCR2A = 0b11000010;
   //TCCR2B = 0b00001101;
  // OCR2A = 188;
   TCCR1A = 0b11110010;		// Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM, Fast PWM mode
   TCCR1B = 0b00011010;		// input noise canceler, input capture rising edge, 1 prescale
   ICR1 = 42000;     		// set period of PWM signal
   OCR1A = 3000;				// set high time of output PWM signal
   OCR1B = 3000;				// set high time of output PWM signal
}

void loop(){
   char Reg_value= mySerial.read();
   Serial.println(Reg_value, BIN);
   char accel = Reg_value&0x03;
   switch(accel)
   {
      case 1: Forward();
              break;
      case 2: Reverse();
              break;
      default:Stop();
   }
   
   char steer = Reg_value & 0xF8;
   steer >> 3;
   analogWrite(11, steer + 56);
  
   if((0x04&Reg_value) == 4)
   {
      tone(buzzerPin,440,2000);
   }
   else
   {
      noTone(buzzerPin);
   }
}

void Stop(void){
  OCR1A	= 3000;
  OCR1B	= 3000;
  for(int i = 0; i<2; i++)
  {
    digitalWrite(front_LED[i], LOW);
    digitalWrite(back_LED[i], LOW);
  }
}

void Forward(void){
OCR1A	= 3400;	
OCR1B	= 2600;	
  for(int i = 0; i<2; i++)
  {
    digitalWrite(front_LED[i], HIGH);
    digitalWrite(back_LED[i], LOW);
  }
}

void Reverse(void){
   OCR1A	= 2600;	
   OCR1B	= 3400;	
   for(int i = 0; i<2; i++)
   {
     digitalWrite(back_LED[i], HIGH);
     digitalWrite(front_LED[i], LOW);
   }
}

