#include "TestObject1.h"
#include <QtCore/qdebug.h>
#include <QtCore/qlogging.h>

void TestObject1::showMessage() {
    qDebug() << "TestObject1 showMessage() called!";

    m_signalSlotSystem.sendSignal(&onShowMessage);
}
