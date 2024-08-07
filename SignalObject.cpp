#include "SignalObject.h"

void SignalObject::showMessage(const std::string& msg) {
    m_system.emitSignal(this, typeid(&SignalObject::showMessage), msg);
}

void SignalObject::addNumbers(int a, int b) {
    m_system.emitSignal(this, typeid(&SignalObject::addNumbers), a, b);
}

void SignalObject::multiplyNumbers(int a, int b, int c) {
    m_system.emitSignal(this, typeid(&SignalObject::multiplyNumbers), a, b, c);
}
