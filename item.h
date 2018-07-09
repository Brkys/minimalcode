#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QDateTime>
#include <QJsonArray>
#include <QJsonObject>


class Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int percentage READ percentage WRITE setPercentage NOTIFY percentageChanged)
public:
    explicit Item();

    Item(const int &percentage);

    int percentage() const { return percentage_; }

    void setPercentage(const int &a);

    void readJson(const QJsonObject &json);

signals:
    percentageChanged();

private:
    int percentage_;

};

#endif // ITEM_H
