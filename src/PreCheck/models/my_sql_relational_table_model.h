#ifndef QQUICKRELATIONALTABLEMODEL_H
#define QQUICKRELATIONALTABLEMODEL_H

#include <QtSql/QSqlRelationalTableModel>
#include <QtSql/QSqlRecord>


class QQuickRelationalTableModel : public QSqlRelationalTableModel
{
        Q_OBJECT
    private:

        QHash<int, QByteArray> roles;   

    public:



        QQuickRelationalTableModel(QString tableName = "", QString filter = "", QObject *parent = 0);


        bool select();

        QSqlRecord record(int row) const;




        QVariant data(const QModelIndex &index, int role) const;

        void applyRoles();

        virtual QHash<int, QByteArray> roleNames() const { return roles; }
        void init(QString tableName, QString filter);
}; //end QQUICKRELATIONALTABLEMODEL_H
#endif
