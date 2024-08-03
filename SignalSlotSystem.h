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
    static SignalSlotSystem& getInstance();

    SignalSlotSystem(const SignalSlotSystem&) = delete;
    SignalSlotSystem& operator=(const SignalSlotSystem&) = delete;

    void connect(Signal* signal, Slot slot);

    template <typename Func, typename... Args>
    void connect(Signal* signal, Func&& func, Args&&... args) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_connections[signal].push_back([func = std::forward<Func>(func), ...args = std::forward<Args>(args)]() {
            func(args...);
        });
    }

    void sendSignal(Signal* signal);
    void sendSignalAsync(Signal* signal);
    void waitForAll();
private:
    SignalSlotSystem();
    std::mutex m_mutex;
    std::vector<std::future<void>> m_futures;
    std::map<Signal*, std::vector<Slot>> m_connections;
};
