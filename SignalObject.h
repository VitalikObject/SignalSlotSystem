#pragma once

#include "SignalSlotSystem.h"
#include "VObject.h"
#include <string>

class SignalObject : VObject{
public:
    void showMessage(const std::string& msg);
    void addNumbers(int a, int b);
    void multiplyNumbers(int a, int b, int c);

private:
    SignalSlotSystem& m_system = SignalSlotSystem::getInstance();
};
