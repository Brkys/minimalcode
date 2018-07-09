#include "item.h"

#include <QDebug>

Item::Item()
{
}

Item::Item(const int &per)
{
    this->setPercentage(per);
}

void Item::setPercentage(const int &a)
{
    if(a != percentage_)
    {
        percentage_ = a;
        emit percentageChanged();
    }
}

void Item::readJson(const QJsonObject &json)
{
    if(json.contains("percent"))
        setPercentage(json["percent"].toInt());
}
