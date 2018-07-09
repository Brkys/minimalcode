#include <QGuiApplication>
#include "worker.h"
#include <QQuickWindow>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //Load files and set up samples
    Worker worker;

    //Creating window from view
    QQuickWindow *quickWindow = qobject_cast<QQuickWindow *>(worker.getView());
    quickWindow->setMinimumWidth(800);
    quickWindow->setMinimumHeight(600);
    quickWindow->show();


    return app.exec();
}
