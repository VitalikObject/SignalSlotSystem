#pragma once

#include <string>
#include "VObject.h"

class SlotObject : VObject {
public:
    void slot(int a, const std::string& b);
};
