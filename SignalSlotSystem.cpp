#include "SignalSlotSystem.h"

SignalSlotSystem& SignalSlotSystem::getInstance() {
    static SignalSlotSystem instance;
    return instance;
}
