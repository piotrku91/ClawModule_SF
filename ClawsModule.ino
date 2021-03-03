#include "ClawMod.hpp"

ClawMod Claw(10);

void setup()
{
Claw.InitServo();
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
Claw.Lock();


}
