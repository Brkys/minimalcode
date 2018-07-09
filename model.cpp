#include "model.h"

MyModel::~MyModel(){
    qDeleteAll(itemList_);
    itemList_.clear();
}

int MyModel::rowCount(const QModelIndex &parent) const{
    return parent.isValid() ? 0 : itemList_.size();
}

QVariant MyModel::data(const QModelIndex &index, int role) const{
    if(role == Qt::UserRole){
        Item *item =  itemList_[index.row()];
        return QVariant::fromValue(item);
    }
    return QVariant();
}

void MyModel::appendItem(Item *item)
{
    itemList_.append(item);
}

QHash<int, QByteArray> MyModel::roleNames() const{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole] = "sample";
    return roles;
}
