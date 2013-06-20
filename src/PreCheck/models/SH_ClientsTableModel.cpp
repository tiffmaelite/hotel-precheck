#include "SH_ClientsTableModel.h"


/*!
 \brief

 \fn ClientsTableModel::ClientsTableModel
 \param parent
*/
SH_ClientsTableModel::SH_ClientsTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("CLIENTS");
}


/*!
 \brief

 \fn ClientsTableModel::fillModel
*/
void SH_ClientsTableModel::fillModel()
{
}
