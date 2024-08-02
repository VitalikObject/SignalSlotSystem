#pragma once
#include <map>
#include <vector>
#include <mutex>
#include <future>

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
    void sendSignalAsync(Signal* signal);
    void waitForAll();
private:
    std::mutex m_mutex;
    std::vector<std::future<void>> m_futures;
    std::map<Signal*, std::vector<Slot>> m_connections;
};
