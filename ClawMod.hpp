#pragma once
#include <Servo.h>

/* 
ClawModule for use with Micro Gripper Kit A - v0.0.2

Written by: Piotr Kupczyk (dajmosster@gmail.com)
GitHub: https://github.com/piotrku91/ClawModule_SF
*/
enum ClawPosAngle // Values of servo rotate (keep in enum for easy calibration)
{
    Open = 120,
    Close = 97
};

class ClawMod
{
private:
    Servo ClawSrv; // Servo object
    int m_Pin; // Arduino pin
    bool m_isOpen; // Status of claw
    bool m_Lock; // Status of lock claw object

public:
//Return status
    bool isOpen();
    bool isLocked();

//Main operations
    void Open();
    void Close();
    void Lock();
    void Unlock();

//Raw access to servo object
    void writeServo(const int& Value);
    int readServo();

//Prepare function
    void InitServo(bool InitToDo=true)
    {
        ClawSrv.attach(m_Pin);
        if (InitToDo) Open(); else Close();
    };

      void InitServoSilent()
    {
        ClawSrv.attach(m_Pin);
    };

//Constructor
    ClawMod(int Pin) : m_Pin{Pin}, m_isOpen{false}, m_Lock{false} {};

//Destructor
    ~ClawMod() {ClawSrv.detach()};
};