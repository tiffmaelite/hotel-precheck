#include "SH_UsersTableModel.h"

/*namespace SimplHotel
{*/
/*!
 \details \~french

 \fn SH_UsersTableModel::SH_UsersTableModel
*/
SH_UsersTableModel::SH_UsersTableModel(QObject *parent):
    SH_ExtendedProxyModel(parent)
{
    SH_ExtendedProxyModel::model->setTableName("USERS");
}

/*!
 \details \~french

 \fn SH_UsersTableModel::fillModel
*/
void SH_UsersTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyModel::model->fieldsList();
    this->setHeaderData(fields.indexOf("ID"), Qt::Horizontal, QObject::tr("ID"));
    this->setHeaderData(fields.indexOf("LOGIN"), Qt::Horizontal, QObject::tr("Nom d'utilisateur"));
    this->setHeaderData(fields.indexOf("IS_RECEPTIONIST"), Qt::Horizontal, QObject::tr("Accès réceptionniste"));
    this->setHeaderData(fields.indexOf("IS_MANAGERX"), Qt::Horizontal, QObject::tr("Accès responsable lecture"));
    this->setHeaderData(fields.indexOf("IS_MANAGERZ"), Qt::Horizontal, QObject::tr("Accès responsable lecture/écriture/exécution"));
    this->setHeaderData(fields.indexOf("IS_ADMINSTRATOR"), Qt::Horizontal, QObject::tr("Accès administrateur"));
    this->sort(fields.indexOf("LOGIN"),Qt::AscendingOrder);
    this->addHiddenColumn(fields.indexOf("ID"));
    QList<int> checkboxes;
    checkboxes.append(fields.indexOf("IS_RECEPTIONIST"));
    checkboxes.append(fields.indexOf("IS_MANAGERX"));
    checkboxes.append(fields.indexOf("IS_MANAGERZ"));
    checkboxes.append(fields.indexOf("IS_ADMINISTRATOR"));
    SH_ExtendedProxyModel::setBooleanColumns(checkboxes);
}
/*}*/
