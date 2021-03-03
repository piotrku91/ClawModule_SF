#include "ClawMod.hpp"

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