#pragma once
#include <Servo.h>

enum ClawPosAngle
{
    Open = 120,
    Close = 97
};

class ClawMod
{
private:
    Servo ClawSrv;
    int m_Pin;
    bool m_isOpen;
    bool m_Lock;

public:
    bool isOpen();
    bool isLocked();

    void Open();
    void Close();
    void Lock();
    void Unlock();

    void InitServo()
    {
        ClawSrv.attach(m_Pin);
        Open();
    };

    //Constructor
    ClawMod(int Pin) : m_Pin{Pin}, m_isOpen{false}, m_Lock{false} {};
};