#pragma once

#include <any>
#include <functional>
#include <future>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <typeindex>

class SignalSlotSystem
{
public:
    using SlotFunction = std::function<void(const std::vector<std::any>&)>;

    static SignalSlotSystem& getInstance();

    SignalSlotSystem(const SignalSlotSystem&) = delete;
    SignalSlotSystem& operator=(const SignalSlotSystem&) = delete;

    template<typename SignalObject, typename... SignalArgs, typename SlotObject, typename... SlotArgs>
    void connect(SignalObject* signalObject, void (SignalObject::*signal)(SignalArgs...),
                 SlotObject* slotObject, void (SlotObject::*slot)(SlotArgs...)) {
        std::lock_guard<std::mutex> lock(m_mutex);
        auto slotFunc = [this, slotObject, slot](const std::vector<std::any>& args) {
            callSlot(slotObject, slot, args);
        };
        m_connections[signalObject][std::type_index(typeid(signal))].push_back(slotFunc);
    }

    template<typename Func, typename... Args>
    void emitSignal(void* signalObject, Func&& func, Args&&... args) {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::vector<std::any> anyArgs = { std::any(std::forward<Args>(args))... };
        const std::type_info& signalType = typeid(func);
        auto& connections = m_connections[signalObject][std::type_index(signalType)];
        for (auto& slotFunc : connections) {
            slotFunc(anyArgs);
        }
    }

    template<typename Func, typename... Args>
    void emitSignalAsync(void* signalObject, Func&& func, Args&&... args) {
        std::vector<std::any> anyArgs = { std::any(std::forward<Args>(args))... };

        std::vector<std::future<void>> futures;

        const std::type_info& signalType = typeid(func);

        futures.push_back(std::async(std::launch::async, [this, signalObject, anyArgs, &signalType]() {
            std::lock_guard<std::mutex> lock(m_mutex);
            auto& connections = m_connections[signalObject][std::type_index(signalType)];
            for (auto& slotFunc : connections) {
                slotFunc(anyArgs);
            }
        }));

        for (auto& future : futures) {
            future.wait();
        }
    }

private:
    SignalSlotSystem() {};
    std::unordered_map<void*, std::unordered_map<std::type_index, std::vector<SlotFunction>>> m_connections;
    std::mutex m_mutex;

    template<typename T>
    static T any_cast_helper(const std::any& operand) {
        try {
            return std::any_cast<T>(operand);
        } catch (const std::bad_any_cast&) {
            throw std::bad_any_cast();
        }
    }

    template<typename SlotObject, typename... Args, std::size_t... Is>
    void callSlotImpl(SlotObject* slotObject, void (SlotObject::*slot)(Args...), const std::vector<std::any>& args, std::index_sequence<Is...>) {
        (slotObject->*slot)(any_cast_helper<Args>(args[Is])...);
    }

    template<typename SlotObject, typename... Args>
    void callSlot(SlotObject* slotObject, void (SlotObject::*slot)(Args...), const std::vector<std::any>& args) {
        if (args.size() != sizeof...(Args)) {
            throw std::invalid_argument("Incorrect number of arguments");
        }
        callSlotImpl(slotObject, slot, args, std::index_sequence_for<Args...>{});
    }
};
