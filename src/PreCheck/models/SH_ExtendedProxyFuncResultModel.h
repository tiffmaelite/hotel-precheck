#ifndef SH_EXTENDEDPROXYFUNCRESULTMODEL_H
#define SH_EXTENDEDPROXYFUNCRESULTMODEL_H

#include <QObject>
#include "SH_SqlFuncResultModel.h"
#include "SH_ExtendedSqlProxyModel.h"

class SH_ExtendedProxyFuncResultModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QString functionCall READ functionCall STORED false)
public:
    explicit SH_ExtendedProxyFuncResultModel(QObject *parent = 0);

    /*!
        \brief \~french

        \fn functionCall
        \return const QString
        */
        const QString functionCall() const { return this->model->functionCall(); }

        Q_INVOKABLE bool fetch();

        void setSourceModel(QAbstractItemModel *sourceModel);
protected:
        SH_SqlFuncResultModel *model;
signals:

public slots:

};

#endif // SH_EXTENDEDPROXYFUNCRESULTMODEL_H
