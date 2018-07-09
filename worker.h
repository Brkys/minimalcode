#ifndef WORKER_H
#define WORKER_H

#include "item.h"
#include "manager.h"
#include <QQmlContext>
#include <QQuickView>

class Worker
{
public:
    Worker();

    QQuickView * getView() const { return view_; }

private:
    QQuickView *view_;

    Manager *manager_;
};

#endif // WORKER_H
