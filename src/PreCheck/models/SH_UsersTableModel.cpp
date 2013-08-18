#include "SH_UsersTableModel.h"

/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_UsersTableModel::SH_UsersTableModel
*/
SH_UsersTableModel::SH_UsersTableModel(QObject *parent):
    SH_ExtendedProxyTableModel(parent)
{
    SH_ExtendedProxyTableModel::model->setTableName("USERS");
    this->fetch();
}

/*!
 \details \~french

 \fn SH_UsersTableModel::fillModel
*/
void SH_UsersTableModel::fillModel()
{
    this->setHeaderData(this->fieldIndex("ID"), Qt::Horizontal, QObject::tr("ID"));
    this->setHeaderData(this->fieldIndex("LOGIN"), Qt::Horizontal, QObject::tr("Nom d'utilisateur"));
    this->setHeaderData(this->fieldIndex("ISRECEPTIONIST"), Qt::Horizontal, QObject::tr("Accès réceptionniste"));
    this->setHeaderData(this->fieldIndex("ISMANAGERX"), Qt::Horizontal, QObject::tr("Accès responsable lecture"));
    this->setHeaderData(this->fieldIndex("ISMANAGERZ"), Qt::Horizontal, QObject::tr("Accès responsable lecture/écriture/exécution"));
    this->setHeaderData(this->fieldIndex("IS_ADMINSTRATOR"), Qt::Horizontal, QObject::tr("Accès administrateur"));
    this->sort(this->fieldIndex("LOGIN"),Qt::AscendingOrder);
    this->addHiddenColumn(this->fieldIndex("ID"));
    QList<int> checkboxes;
    checkboxes.append(this->fieldIndex("ISRECEPTIONIST"));
    checkboxes.append(this->fieldIndex("ISMANAGERX"));
    checkboxes.append(this->fieldIndex("ISMANAGERZ"));
    checkboxes.append(this->fieldIndex("ISADMINISTRATOR"));
    SH_ExtendedProxyTableModel::setBooleanColumns(checkboxes);
}
/*}*/
