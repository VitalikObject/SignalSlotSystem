#include "SlotObject.h"
#include <iostream>

void SlotObject::showMessage(const std::string& msg) {
    std::cout << "Message: " << msg << std::endl;
}

void SlotObject::addNumbers(int a, int b) {
    std::cout << "Sum of numbers: " << (a + b) << std::endl;
}

void SlotObject::multiplyNumbers(int a, int b, int c) {
    std::cout << "Product of numbers: " << (a * b * c) << std::endl;
}
