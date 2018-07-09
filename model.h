#ifndef MODEL_H
#define MODEL_H

#include "item.h"
#include <QAbstractListModel>
#include <QSortFilterProxyModel>

class MyModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ~MyModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void appendItem(Item * item);

    QHash<int, QByteArray> roleNames() const;

private:
    QList<Item *> itemList_;
};


#endif // MODEL_H
