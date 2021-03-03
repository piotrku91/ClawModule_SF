#include "ClawMod.hpp"

/* 
ClawModule for use with Micro Gripper Kit A - v0.0.2

Written by: Piotr Kupczyk (dajmosster@gmail.com)
GitHub: https://github.com/piotrku91/ClawModule_SF
*/

bool ClawMod::isOpen()
{

    if (ClawSrv.read() == ClawPosAngle::Open)
    {
        m_isOpen = true;
        return true;
    };

    m_isOpen = false;
    return false;
};

bool ClawMod::isLocked()
{
    return m_Lock;
};

void ClawMod::Open()
{
    if ((!m_isOpen) && (!m_Lock))
    {
        ClawSrv.write(ClawPosAngle::Open);
        m_isOpen = true;
    };
};

void ClawMod::Close()
{
    if ((m_isOpen) && (!m_Lock))
    {
        ClawSrv.write(ClawPosAngle::Close);
        m_isOpen = false;
    };
};

void ClawMod::Lock()
{
    m_Lock = true;
};

void ClawMod::Unlock()
{
    m_Lock = false;
};

void ClawMod::writeServo(const int& Value)
{
    ClawSrv.write(Value);
};

int ClawMod::readServo()
{
    return ClawSrv.read();
};