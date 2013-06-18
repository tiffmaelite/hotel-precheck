#include "services_table_model.h"


/*!
 \brief

 \fn ServicesTableModel::ServicesTableModel
 \param parent
*/
ServicesTableModel::ServicesTableModel(QObject *parent):
    CheckableSortFilterProxyModel(parent)
{
    CheckableSortFilterProxyModel::model->setTable("SERVICESINFOS");
}


/*!
 \brief

 \fn ServicesTableModel::fillModel
*/
void ServicesTableModel::fillModel()
{
    CheckableSortFilterProxyModel::sort(1,Qt::AscendingOrder);
}
