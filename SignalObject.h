#pragma once

#include "SignalSlotSystem.h"
#include "VObject.h"
#include <string>

class SignalObject : VObject{
public:
    void signal(int a, const std::string& b);

private:
    SignalSlotSystem& m_system = SignalSlotSystem::getInstance();
};
