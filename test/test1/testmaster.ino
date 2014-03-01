//master slave test
//master code
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11); //arduino to bluetooth


void setup()
{
	Serial.begin(115200);
	mySerial.begin(9600);
}

void loop()
{
	if(Serial.available()>0)
	{
		if(Serial.read() == 'o')
		{
			mySerial.write('n');
		}
	}
}
