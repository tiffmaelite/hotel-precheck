#include "SH_TraineesTableModel.h"

/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_TraineesTableModel::SH_TraineesTableModel
*/
SH_TraineesTableModel::SH_TraineesTableModel(QObject *parent):
    SH_ExtendedProxyTableModel(parent)
{
    SH_ExtendedProxyTableModel::model->setTableName("TRAINEES");
}

/*!
 \details \~french

 \fn SH_TraineesTableModel::fillModel
*/
void SH_TraineesTableModel::fillModel()
{
    this->setHeaderData(this->fieldIndex("ID"), Qt::Horizontal, QObject::tr("ID"));
    this->setHeaderData(this->fieldIndex("LOGIN"), Qt::Horizontal, QObject::tr("Nom d'utilisateur"));
    this->addHiddenColumn(this->fieldIndex("ID"));
    this->sort(this->fieldIndex("LOGIN"),Qt::AscendingOrder);
}
/*}*/
