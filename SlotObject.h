#pragma once

#include <string>
#include "VObject.h"

class SlotObject : VObject {
public:
    void showMessage(const std::string& msg);
    void addNumbers(int a, int b);
    void multiplyNumbers(int a, int b, int c);
    void mergeStrings(const std::string& str1, const std::string& str2);
};
