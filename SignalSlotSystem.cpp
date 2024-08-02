#include "SignalSlotSystem.h"

SignalSlotSystem::SignalSlotSystem() {}


SignalSlotSystem& SignalSlotSystem::getInstance() {
    static SignalSlotSystem instance;
    return instance;
}

void SignalSlotSystem::connect(Signal* signal, Slot slot) {
    m_connections[signal].push_back(slot);
}

void SignalSlotSystem::sendSignal(Signal* signal) {
    if(m_connections.find(signal) != m_connections.end()) {
        for (auto& slot : m_connections[signal]) {
            slot();
        }
    }
}
