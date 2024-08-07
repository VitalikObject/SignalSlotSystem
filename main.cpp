#include "SignalObject.h"
#include "SlotObject.h"

int main(int argc, char *argv[])
{
    SignalSlotSystem& signalSlotSystem = SignalSlotSystem::getInstance();
    SignalObject signalObject;
    SlotObject slotObject;

    signalSlotSystem.connect(&signalObject, &SignalObject::showMessage, &slotObject, &SlotObject::showMessage);
    signalSlotSystem.connect(&signalObject, &SignalObject::addNumbers, &slotObject, &SlotObject::addNumbers);
    signalSlotSystem.connect(&signalObject, &SignalObject::multiplyNumbers, &slotObject, &SlotObject::multiplyNumbers);

    signalSlotSystem.connect(&signalObject, &SignalObject::mergeStringsAsync, &slotObject, &SlotObject::mergeStrings);

    signalObject.showMessage("hello");
    signalObject.addNumbers(4, 5);
    signalObject.multiplyNumbers(4, 5, 6);

    signalObject.mergeStringsAsync("Hello, ", "World!");

    return 0;
}
