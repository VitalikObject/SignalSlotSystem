#include "TestObject3.h"
#include <QtCore/qdebug.h>
#include <QtCore/qlogging.h>

void TestObject3::showMessage(int a, std::string b) {
    qDebug() << "TestObject2 showMessage() called with arguments: " << std::to_string(a) << ", " << b;
}
