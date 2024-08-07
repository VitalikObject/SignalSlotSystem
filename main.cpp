#include "SignalObject.h"
#include "SlotObject.h"

int main(int argc, char *argv[])
{
    SignalSlotSystem& signalSlotSystem = SignalSlotSystem::getInstance();
    SignalObject signalObject;
    SlotObject slotObject;

    signalSlotSystem.connect(&signalObject, &SignalObject::signal, &slotObject, &SlotObject::slot);
    signalObject.signal(42, "hello");

    return 0;
}
