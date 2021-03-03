#include "ClawMod.hpp"

/* 
ClawModule for use with Micro Gripper Kit A - v0.0.2

Written by: Piotr Kupczyk (dajmosster@gmail.com)
GitHub: https://github.com/piotrku91/ClawModule_SF
*/

ClawMod Claw(10); // Create object with access to servo by Pin as argument (Arduino Pin 10).

void setup()
{
Claw.InitServo(); // Attach servo and run open action.
Serial.begin(9600);
}

void loop()
{
delay(1000);
if (Claw.isLocked()) Serial.println("Claw is locked!");
Claw.Open();
if (Claw.isOpen()) Serial.println("Claw is open!");
delay(3000);
Claw.Close();
if (!Claw.isOpen()) Serial.println("Claw is closed!");
delay(2000);
Claw.Lock(); // If is lock, its impossible to open or close claw. 


}
