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

    signalObject.showMessage("hello");
    signalObject.addNumbers(4, 5);
    signalObject.multiplyNumbers(4, 5, 6);

    return 0;
}
