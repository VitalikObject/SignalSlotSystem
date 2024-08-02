#include "TestObject2.h"
#include <QtCore/qdebug.h>
#include <QtCore/qlogging.h>

void TestObject2::showMessage() {
    qDebug() << "TestObject2 showMessage() called!";
}
