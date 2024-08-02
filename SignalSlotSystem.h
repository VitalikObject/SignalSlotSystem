#pragma once
#include <map>
#include <vector>

using Signal = std::function<void()>;
using Slot = std::function<void()>;

class SignalSlotSystem
{
public:
    SignalSlotSystem();
    static SignalSlotSystem& getInstance();

    SignalSlotSystem(const SignalSlotSystem&) = delete;
    SignalSlotSystem& operator=(const SignalSlotSystem&) = delete;

    void connect(Signal* signal, Slot slot);
    void sendSignal(Signal* signal);
private:
    std::map<Signal*, std::vector<Slot>> m_connections;
};
