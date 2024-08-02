#include <QCoreApplication>
#include "SignalSlotSystem.h"
#include "TestObject1.h"
#include "TestObject2.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SignalSlotSystem &signalSlotSystem = SignalSlotSystem::getInstance();
    TestObject1 testObject1;
    TestObject2 testObject2;

    signalSlotSystem.connect(&testObject1.onShowMessage, [&testObject2] { testObject2.showMessage(); });
    signalSlotSystem.sendSignal(&testObject1.onShowMessage);

    testObject1.showMessage();

    return a.exec();
}
