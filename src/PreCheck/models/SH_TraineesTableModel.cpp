#include "SH_TraineesTableModel.h"

/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_TraineesTableModel::SH_TraineesTableModel
*/
SH_TraineesTableModel::SH_TraineesTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTable("TRAINEES");
}

/*!
 \details \~french

 \fn SH_TraineesTableModel::fillModel
*/
void SH_TraineesTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyModel::model->fieldsList();
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("ID"), Qt::Horizontal, QObject::tr("ID"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("LOGIN"), Qt::Horizontal, QObject::tr("Nom d'utilisateur"));
    SH_ExtendedProxyModel::addFilterKeyColumn(fields.indexOf("LOGIN"));
}
/*}*/
