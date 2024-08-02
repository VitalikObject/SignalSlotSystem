#pragma once
#include "VObject.h"
#include "SignalSlotSystem.h"

class TestObject1 : public VObject
{
public:
    Signal onShowMessage;
    void showMessage();
private:
    SignalSlotSystem &m_signalSlotSystem = SignalSlotSystem::getInstance();
};
