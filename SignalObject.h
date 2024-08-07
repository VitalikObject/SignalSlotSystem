#pragma once

#include "SignalSlotSystem.h"
#include "VObject.h"
#include <string>

class SignalObject : VObject{
public:
    void showMessage(const std::string& msg);
    void addNumbers(int a, int b);
    void multiplyNumbers(int a, int b, int c);
    void mergeStringsAsync(const std::string& str1, const std::string& str2);

private:
    SignalSlotSystem& m_system = SignalSlotSystem::getInstance();
};
