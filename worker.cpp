#include "worker.h"

Worker::Worker() :
    view_(new QQuickView()),
    manager_(new Manager("C:/Projects/minimal/data"))
{
    view_->setResizeMode(QQuickView::SizeRootObjectToView);
    view_->rootContext()->setContextProperty("manager", manager_);
    view_->setSource(QUrl::fromLocalFile(QStringLiteral(":/main.qml")));
}
