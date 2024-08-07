#include "SignalObject.h"

void SignalObject::showMessage(const std::string& msg) {
    m_system.emitSignal(this, &SignalObject::showMessage, msg);
}

void SignalObject::addNumbers(int a, int b) {
    m_system.emitSignal(this, &SignalObject::addNumbers, a, b);
}

void SignalObject::multiplyNumbers(int a, int b, int c) {
    m_system.emitSignal(this, &SignalObject::multiplyNumbers, a, b, c);
}

void SignalObject::mergeStringsAsync(const std::string& str1, const std::string& str2) {
    m_system.emitSignal(this, &SignalObject::mergeStringsAsync, str1, str2);
}
