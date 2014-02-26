Trivial Bluetooth Controlled Car
====
Description:
2 Arduinos will be used in this project, one for the remote and one attached
to the car. The arduino on the remote will be used to transfer data 
while the one on car will be used to control the car. Data transfer will
be handled with serial communication using bluetooth.

###Remote Arduino (TX):

Each control from the remote will be mapped to a character which will be
sent to the car through bluetooth

CONTROLS:

Potentiometer: Controls the steering

Photoresistor: Speed of the car

for both controls need to figure out:
1) how the range of each read signal will be mapped to a character
2) how to not have these characters intefere with each other (Example: '1' needs to be mapped to either speed or steering, not both)

Button 1: Forward/ Reverse
'f' = forward 
'r' = reverse
 
Button 2: Turn on/ Turn Off
'e' = on
'd' = off

###Car Arduino (RX):

Each character recieved through will represent an action to perform on the car


###Communication/Etc:


