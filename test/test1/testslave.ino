//master slave test
//slave code
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11); //arduino to bluetooth (RX,TX)

void setup()
{
	mySerial.begin(9600);
	pinMode(9,OUTPUT);
}

void loop()
{
	static boolean test = false;
	if(mySerial.available()>0)
	{
		if(mySerial.read() == 'n')
		{
			if(test == true)
			{
				test = false;
				digitalWrite(9,HIGH);
			}

			else
			{
				test == true;
				digitalWrite(9,LOW);
			}	
		}
	}
}
