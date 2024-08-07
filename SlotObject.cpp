#include "SlotObject.h"
#include <iostream>

void SlotObject::slot(int a, const std::string& b) {
    std::cout << "slot called with: " << a << ", " << b << std::endl;
}
