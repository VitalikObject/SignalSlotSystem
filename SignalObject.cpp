#include "SignalObject.h"

void SignalObject::signal(int a, const std::string& b) {
    std::vector<std::any> args;
    args.push_back(a);
    args.push_back(b);
    m_system.emitSignal(this, typeid(&SignalObject::signal), args);
}
