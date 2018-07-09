#ifndef MANAGER_H
#define MANAGER_H

#include "model.h"
#include <QDir>
#include <QJsonDocument>
#include <QFile>
#include <QSortFilterProxyModel>
#include "sortmodel.h"

class Manager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MyModel* model READ model WRITE setModel NOTIFY modelChanged)
public:
    Manager(const QString &path);

    MyModel *model() const { return model_.get(); }

    void setModel(MyModel *model);

private:
    QJsonObject getJsonObjectFromPath(QString &path);

private:
    QScopedPointer<MyModel> model_;

signals:
    modelChanged();
};


#endif // MANAGER_H
