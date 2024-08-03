#pragma once
#include "VObject.h"
#include <string>

class TestObject3 : public VObject
{
public:
    void showMessage(int a, std::string b);
};
