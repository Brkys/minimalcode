#ifndef SORTMODEL_H
#define SORTMODEL_H

#include <QSortFilterProxyModel>

class SampleSortModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    SampleSortModel();

    void setFilterLocationAddress(const QString &loc);

    void setFilterMinConfidenceLevel(const int &conf);
};

#endif // SORTMODEL_H
