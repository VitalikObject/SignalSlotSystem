#include "SignalSlotSystem.h"
#include <future>

SignalSlotSystem::SignalSlotSystem() {}

SignalSlotSystem& SignalSlotSystem::getInstance() {
    static SignalSlotSystem instance;
    return instance;
}

void SignalSlotSystem::connect(Signal* signal, Slot slot) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_connections[signal].push_back(slot);
}

void SignalSlotSystem::sendSignal(Signal* signal) {
    std::vector<Slot> slotsToExecute;
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_connections.find(signal) != m_connections.end()) {
            slotsToExecute = m_connections[signal];
        }
    }
    for (auto& slot : slotsToExecute) {
        slot();
    }
}

void SignalSlotSystem::sendSignalAsync(Signal* signal) {
    std::vector<Slot> slotsToExecute;
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_connections.find(signal) != m_connections.end()) {
            slotsToExecute = m_connections[signal];
        }
    }
    m_futures.push_back(std::async(std::launch::async, [slotsToExecute]() {
        for (auto& slot : slotsToExecute) {
            slot();
        }
    }));
}

void SignalSlotSystem::waitForAll() {
    for (auto& future : m_futures) {
        future.get();
    }
    m_futures.clear();
}
