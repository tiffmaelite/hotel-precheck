#ifndef CHECKABLESORTFILTERPROXYMODEL_H
#define CHECKABLESORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "qQuickRelationalTableModel.h"

class CheckableSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QQuickRelationalTableModel *model READ model WRITE setModel);
public:
    CheckableSortFilterProxyModel(QString tableName, QString filter = "", QObject *parent = 0);

    QQuickRelationalTableModel*	 model() const;
    void	 setModel(QQuickRelationalTableModel *m);

    void setParameters(QList<int> boolCols, QList<int> readonlyCols, QList<int> passwordCols);
    void setNullAndNotNullColumns(QList<int> nullCols, QList<int> notNullCols);

    void validate();

    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    Qt::ItemFlags flags ( const QModelIndex & index ) const;



protected:
    bool filterAcceptsRow ( int source_row, const QModelIndex & source_parent ) const;
    virtual void fillModel() = 0;

signals:

public slots:

private:
    QList<int> booleanSet;
    QList<int> passwordSet;
    QList<int> readonlySet;
    QList<int> notNullSet;
    QList<int> nullSet;
    QQuickRelationalTableModel *m_model;

};
#endif
