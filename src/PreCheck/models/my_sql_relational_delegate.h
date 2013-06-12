
#include <QtSql>
#include <QtSql/QSqlRelationalDelegate>
#include <QtWidgets/QWidget>
#include <QAbstractItemModel>
#include <QtWidgets/QStyleOptionViewItem>

#ifndef MYSQLRELATIONALDELEGATE_H
#define MYSQLRELATIONALDELEGATE_H



class mySqlRelationalDelegate : public QSqlRelationalDelegate
{

        Q_OBJECT
    public:


        mySqlRelationalDelegate(QObject *parent = 0);



        QWidget *createEditor(QWidget *aParent, const QStyleOptionViewItem &option, const QModelIndex &index) const;


        void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;


        void setEditorData(QWidget *editor, const QModelIndex &index) const;

    signals:

    public slots:

};

#endif // MYSQLRELATIONALDELEGATE_H
