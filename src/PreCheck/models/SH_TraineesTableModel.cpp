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
    QStringList fields = SH_ExtendedProxyTableModel::model->fieldsList();
    this->setHeaderData(fields.indexOf("ID"), Qt::Horizontal, QObject::tr("ID"));
    this->setHeaderData(fields.indexOf("LOGIN"), Qt::Horizontal, QObject::tr("Nom d'utilisateur"));
    this->addHiddenColumn(fields.indexOf("ID"));
    this->sort(fields.indexOf("LOGIN"),Qt::AscendingOrder);
}
/*}*/