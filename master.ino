#include "Arduino.h"
#include <SoftwareSerial.h>

// PORTC
#define POT    0x00
#define PHOTO1 0x01
#define PHOTO2 0x02
// PORTB
#define SW1    0x20
#define SW2    0x10

SoftwareSerial mySerial(10,11); //arduino to bluetooth

char PC[] = {POT,PHOTO1,PHOTO2};
char PB[] = {SW1};

void setup(void){
  
  for(int i=0;i<sizeof(PC);i++){
    DDRC &= ~PC[i];
  }
  
  for(int i=0;i<sizeof(PB);i++){
    DDRB  &= ~PB[i];
    PORTB |= PB[i];
  }
  
  ADC_Init();
  
  Serial.begin(9600);
}

void loop(void){
  static char Master_Reg = analogRead(0);
  Serial.println(Master_Reg);
  delay(1000);
}

char Register_Update(void){
  return ((Steer()<<3)|(Horn()<<2)|(Photo_ReadR(Update_Thresh_P2())<<1)|(Photo_ReadF(Update_Thresh_P1())));
}

char Photo_ReadF(int thresh){
  return (Get_ADC(PHOTO1)<thresh)?1:0;
}

char Photo_ReadR(int thresh){
  return (Get_ADC(PHOTO2)<thresh)?1:0;
}

char Steer(void){
  return map(analogRead(POT),0,1023,0,31);
}

char Horn(void){
  return (PINB&SW1)?0:1;
}

int Update_Thresh_P1(void){
  static int thresh_P1 = Get_ADC(PHOTO1)-20;

  return thresh_P1 = (PINB&SW2)?thresh_P1:(Get_ADC(PHOTO1)-20);
}

int Update_Thresh_P2(void){
  static int thresh_P2 = Get_ADC(PHOTO2)-20;

  return thresh_P2 = (PINB&SW2)?thresh_P2:(Get_ADC(PHOTO2)-20);
}

void ADC_Init(void){
  // REFS1:0 = 01, AVCC as reference; ADLAR = 0, Left adjust; MUX3:0 = 0000, ADC0 as input
  ADMUX  &= 0b00010000;
  ADMUX  |= 0b01000000;  
  // ADEN = 1: enable ADC; ADSC = 0: don't start conversion; ADATE = 0: disable auto trigger; ADIE  = 0: disable ADC interrupt; ADPS2:0 = 100: prescaler = 16
  ADCSRA  = 0b10000100;  
}

int Get_ADC(char port){   // get adc result
  // set ADC input
  ADMUX  &= 0xF0;
  ADMUX  |= port;
  
  ADCSRA |= 0x40;	 // start conversion
  while (ADCSRA&0x40){;} // Wait until conversion is completed
  return ADC;	         // return total result
}
