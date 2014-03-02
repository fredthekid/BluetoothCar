void setup(){
  pinMode(13,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  TCCR1A	= 0b11110010;		// Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM, Fast PWM mode
  TCCR1B	= 0b00011010;		// input noise canceler, input capture rising edge, 1 prescale
  ICR1	= 42000;     					// set period of PWM signal
OCR1A	= 3000;					// set high time of output PWM signal
OCR1B	= 3000;					// set high time of output PWM signal
}

void loop(){
  switch(ReadSW1()|ReadSW2()){
    case 1: Forward();
            break;
    case 2: Reverse();
            break;
    default:Stop();
  }
 // analogWrite(6,map(analogRead(0),0,1023,0,255));
 //OCR1A = map(analogRead(0),0,1023,3000,6000);
}

void Stop(void){
  OCR1A	= 3000;	
  OCR1B	= 3000;	
}

void Forward(void){
  OCR1A	= 3400;	
  OCR1B	= 2600;	  
}

void Reverse(void){
  OCR1A	= 2600;	
  OCR1B	= 3400;	
}

int ReadSW1(void){
  return digitalRead(13)?0:1;
}

int ReadSW2(void){
  return digitalRead(12)?0:2;
}
