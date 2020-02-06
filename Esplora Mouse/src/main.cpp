#include <Arduino.h>
#include <Esplora.h>
#include <Mouse.h>

int xDrift = map(Esplora.readJoystickX(), -512, 512, 10, -10);
int yDrift = map(Esplora.readJoystickY(), -512, 512, -10, 10);

void setup()
{
  Serial.begin(9600);       // initialize serial communication with your computer
  Mouse.begin();            // take control of the mouse
}

void loop()
{
  int xValue = Esplora.readJoystickX();        // read the joystick's X position
  int yValue = Esplora.readJoystickY();        // read the joystick's Y position
  int button = Esplora.readJoystickSwitch();   // read the joystick pushbutton
  Serial.print("\nJoystick X: ");                // print a label for the X value
  Serial.print(xValue);                        // print the X value
  Serial.print("\tY: ");                       // print a tab character and a label for the Y value
  Serial.print(yValue);                        // print the Y value
  Serial.print("\tButton: ");                  // print a tab character and a label for the button
  Serial.print(button);                        // print the button value
  Serial.print("\txDrift: ");
  Serial.print(xDrift);
  Serial.print("\tyDrift: ");
  Serial.print(yDrift);
  int mouseX = map( xValue,-512, 512, 10, -10);  // map the X value to a range of movement for the mouse X
  int mouseY = map( yValue,-512, 512, -10, 10);  // map the Y value to a range of movement for the mouse Y
  Serial.print("\tmouseX: ");
  Serial.print(mouseX);
  Serial.print("\tmouseY: ");
  Serial.print(mouseY);
  Mouse.move(mouseX-xDrift/10, mouseY-yDrift/10, 0);                 // move the mouse
 
  delay(10);                                  // a short delay before moving again
}

