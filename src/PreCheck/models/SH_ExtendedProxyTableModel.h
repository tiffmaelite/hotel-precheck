#ifndef SH_EXTENDEDPROXYTABLEMODEL_H
#define SH_EXTENDEDPROXYTABLEMODEL_H
#include "SH_ExtendedSqlProxyModel.h"

class SH_ExtendedProxyTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QString table READ tableName STORED false)
public:
    explicit SH_ExtendedProxyTableModel(QObject *parent = 0);

    /*!
        \brief \~french

        \fn tableName
        \return const QString
        */
        const QString tableName() const { return this->model->tableName(); }

        Q_INVOKABLE bool fetch();

        void setSourceModel(QAbstractItemModel *sourceModel);
protected:
        SH_SqlDataModel *model;
signals:

public slots:

};

#endif // SH_EXTENDEDPROXYTABLEMODEL_H
