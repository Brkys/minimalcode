#include "manager.h"

#include <QDebug>

Manager::Manager(const QString &path)
{
    setModel(new MyModel);
    QDir dir;
    if(dir.exists(path))
    {
        dir = QDir(path);
        for(QString item : dir.entryList())
        {
            if(item.endsWith(".json"))
            {
                //Reading from .json file and adding it's object to object list
                QString filePath = path + "/" + item;
                qDebug() << "Loading data file: " << filePath;
                Item *item = new Item();
                QJsonObject obj = getJsonObjectFromPath(filePath);
                item->readJson(obj);
                model_.get()->appendItem(item);
                emit modelChanged();
            }
        }
    }
    else
        qDebug() << "Path " << dir.path() + " does not exist!";
}

QJsonObject Manager::getJsonObjectFromPath(QString &path)
{
    QString val;
    QFile file;
    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    file.close();
    return doc.object();
}


void Manager::setModel(MyModel *model){
    if(model_.get() == model)
        return;
    model_.reset(model);
}
