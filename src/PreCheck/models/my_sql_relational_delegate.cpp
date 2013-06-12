#include "my_sql_relational_delegate.h"
#include "checkable_sort_filter_proxy_model.h"
#include "my_sql_relational_table_model.h"
#include <QtSql/QSqlRelationalDelegate>
#include <QtSql/QSqlRelationalTableModel>
#include <QtCore/QSortFilterProxyModel>

#include <QDebug>
#include <QSqlRecord>


mySqlRelationalDelegate::mySqlRelationalDelegate(QObject *parent):
    QSqlRelationalDelegate(parent)
{
}



QWidget *mySqlRelationalDelegate::createEditor(QWidget *aParent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    const CheckableSortFilterProxyModel *proxyModel = qobject_cast<const CheckableSortFilterProxyModel *>(index.model());
    QSqlTableModel *childModel = NULL;
    QQuickRelationalTableModel *sqlModel = NULL;
    if (proxyModel)
    {
        sqlModel = qobject_cast<QQuickRelationalTableModel *>(proxyModel->sourceModel());
        if (sqlModel)
        {
            childModel = sqlModel->relationModel(index.column());
        }
    }
    if (childModel)
    {
        QComboBox *combo = new QComboBox(aParent);
        combo->setModel(childModel);
        combo->setModelColumn(childModel->fieldIndex(sqlModel->relation(index.column()).displayColumn()));
        combo->installEventFilter(const_cast<mySqlRelationalDelegate *>(this));
        return combo;
    }
    else
    {
        return QItemDelegate::createEditor(aParent, option, index);
    }

}


void mySqlRelationalDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString strVal = "";
    QComboBox *combo = qobject_cast<QComboBox *>(editor);
    const CheckableSortFilterProxyModel *proxyModel = qobject_cast<const CheckableSortFilterProxyModel *>(index.model());
    if (proxyModel)
    {
        strVal = proxyModel->data(index).toString();
    }
    if (!strVal.isEmpty() && combo)
    {
        combo->setCurrentIndex(combo->findText(strVal));
    }
    else
    {
        QItemDelegate::setEditorData(editor, index);
    }
}


void mySqlRelationalDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.isValid())
    {
        CheckableSortFilterProxyModel *proxyModel = qobject_cast<CheckableSortFilterProxyModel *>(model);
        QQuickRelationalTableModel *sqlModel = NULL;
        QSqlTableModel *childModel = NULL;
        QComboBox *combo = qobject_cast<QComboBox *>(editor);
        if (proxyModel)
        {
            sqlModel = qobject_cast<QQuickRelationalTableModel *>(proxyModel->sourceModel());
            if (sqlModel)
            {
                childModel = sqlModel->relationModel(index.column());
            }
        }
        if (childModel && combo)
        {
            int currentItem = combo->currentIndex();
            int childColIndex = childModel->fieldIndex(sqlModel->relation(index.column()).displayColumn());
            int childEditIndex = childModel->fieldIndex(sqlModel->relation(index.column()).indexColumn());

            proxyModel->setData(index, childModel->data(childModel->index(currentItem, childColIndex), Qt::DisplayRole), Qt::DisplayRole);
            proxyModel->setData(index, childModel->data(childModel->index(currentItem, childEditIndex), Qt::EditRole), Qt::EditRole);
        }
        else
        {
            QItemDelegate::setModelData(editor, model, index);
        }
    }
}
