#include <QCoreApplication>
#include "SignalSlotSystem.h"
#include "TestObject1.h"
#include "TestObject2.h"
#include "TestObject3.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SignalSlotSystem &signalSlotSystem = SignalSlotSystem::getInstance();
    TestObject1 testObject1;
    TestObject2 testObject2;
    TestObject3 testObject3;

    signalSlotSystem.connect(&testObject1.onShowMessage, [&testObject2] { testObject2.showMessage(); });
    signalSlotSystem.connect(&testObject1.onShowMessage, [&testObject3](int a, std::string b) { testObject3.showMessage(a, b); }, 1, "hello");
    signalSlotSystem.sendSignal(&testObject1.onShowMessage);
    signalSlotSystem.sendSignalAsync(&testObject1.onShowMessage);

    testObject1.showMessage();

    signalSlotSystem.waitForAll();

    return a.exec();
}
