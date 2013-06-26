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
    SH_ExtendedProxyModel::model->setTable("USERS");
}

/*!
 \details \~french

 \fn SH_UsersTableModel::fillModel
*/
void SH_UsersTableModel::fillModel()
{
    QStringList fields = SH_ExtendedProxyModel::model->fieldsList();
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("ID"), Qt::Horizontal, QObject::tr("ID"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("LOGIN"), Qt::Horizontal, QObject::tr("Nom d'utilisateur"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("IS_RECEPTIONIST"), Qt::Horizontal, QObject::tr("Accès réceptionniste"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("IS_MANAGERX"), Qt::Horizontal, QObject::tr("Accès responsable lecture"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("IS_MANAGERZ"), Qt::Horizontal, QObject::tr("Accès responsable lecture/écriture/exécution"));
    SH_ExtendedProxyModel::model->setHeaderData(fields.indexOf("IS_ADMINSTRATOR"), Qt::Horizontal, QObject::tr("Accès administrateur"));
    SH_ExtendedProxyModel::addFilterKeyColumn(fields.indexOf("LOGIN"));
    QList<int> checkboxes;
    checkboxes.append(fields.indexOf("IS_RECEPTIONIST"));
    checkboxes.append(fields.indexOf("IS_MANAGERX"));
    checkboxes.append(fields.indexOf("IS_MANAGERZ"));
    checkboxes.append(fields.indexOf("IS_ADMINISTRATOR"));
    SH_ExtendedProxyModel::setBooleanColumns(checkboxes);
}
/*}*/
