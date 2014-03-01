//master slave test
//master code
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11); //arduino to bluetooth


void setup()
{
	mySerial.begin(9600);
	pinMode(8,INPUT);
}

void loop()
{
	boolean button = false;
	if(digitalRead(8)==LOW)
	{
		button = true;
	}

	if(button)
	{
		mySerial.write('n');
	}
      delay(100);
}
