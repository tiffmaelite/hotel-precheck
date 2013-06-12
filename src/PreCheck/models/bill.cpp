#include "bill.h"

Bills::Bills(QString filter, QObject *parent);
    QSqlRelationalTableModel(parent)
{
this->setTable("bills");
this->setFilter(filter);
this->setRelation(0, QSqlRelation("clients", "id", "name"));
this->setRelation(1, QSqlRelation("rooms", "id", "number"));
this->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom client"));
this->setHeaderData(1, Qt::Horizontal, QObject::tr("Chambre"));
this->setHeaderData(2, Qt::Horizontal, QObject::tr("Date arriv�e"));
this->setHeaderData(3, Qt::Horizontal, QObject::tr("Date d�part pr�vue"));
	
this->setSort(2, Qt::AscendingOrder);
this->select();
}