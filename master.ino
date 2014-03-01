//Remote (Master Bluetooth)

#include <SoftwareSerial.h>

SoftwareSerial Master(9,10); // 9 = RX, 10 = TX

void configbluetooth()
{
  Serial.begin(115200); //serial between computer and uno

  Serial.println("Waiting for computer to UNO connection...");
  while(!Serial){;} //wait for connection
  Serial.println("Connected!");

  Master.begin(9600)


  Serial.print("$$$"); //enter command mode
  Serial.println("SM,1"); // set to master mode
  Serial.println("I,10"); 



  Serial.println("SR,asdf"); //store slave address
  Serial.println("C"); //connect to slave


  Serial.println("---");//exit command mode
}
