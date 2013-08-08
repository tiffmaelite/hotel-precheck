#include "SH_SqlQueryModel.h"
#include <QDir>
#include <QDebug>
#include "SH_MessageManager.h"
#include <QtSql/QSqlDriver>
#include <QtCore>
#include "SH_DatabaseManager.h"


SH_SqlQueryModel::SH_SqlQueryModel(QObject *parent) :
    QAbstractListModel(parent), m_new(true)
{
}

/*!
 \details \~french
 \fn SH_SqlQueryModel::rowCount
*/
int SH_SqlQueryModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return this->m_records.count();
}
/*!
 \details \~french
 \fn SH_SqlQueryModel::data
*/
QVariant SH_SqlQueryModel::data(const QModelIndex &index, int role) const
{
    if (!this->m_new && this->m_records.count() > 0)
    {
        int row = index.row();
        int column = this->fieldFromRole(role);
        int nbCols = this->m_roles.count();
        if(column >= 0 && column < nbCols) {
            SH_MessageManager::debugMessage(QString("row : %1, column : %2, field: %3 (%4), value : %5\n").arg(index.row()).arg(index.column()).arg(column).arg(QString(this->m_fields.at(column)->role())).arg(this->m_records.at(row).value(column).toString()));
            return this->m_records.at(row).value(column);
        } else{
            SH_MessageManager::errorMessage(QString("rien à retourner pour %1x%2x%3 (%4>=%5)").arg(index.row()).arg(index.column()).arg(role).arg(column).arg(nbCols));
        }
    }
    SH_MessageManager::errorMessage("modèle vide");
    return QVariant();
}

/*!
 \details \~french
 \fn SH_SqlQueryModel::datas
*/
QVariantMap SH_SqlQueryModel::datas()
{
    //SH_MessageManager::debugMessage("datas");
    QVariantMap result;
    if (this->m_new || this->m_records.count() <= 0)
    {
        this->fetch();
    }
    if (this->m_records.count() > 0)
    {
        for(int column = 0; column < this->m_roles.count(); column++) {
            for(int row = 0; row < this->m_records.count();row++) {
                //SH_MessageManager::debugMessage( "data inserted");
                result.insertMulti(this->m_roles.value(column),this->m_records.at(row).value(column));
            }
        }
    }
    return result;
}

/*!
 \details \~french
 \fn SH_SqlQueryModel::setHeaderData
*/
bool SH_SqlQueryModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    Q_UNUSED(role);
    if (orientation == Qt::Horizontal)
    {
        this->m_fields.at(section)->setText(value.toString().toUpper());
        return (this->m_fields.at(section)->text() == value.toString().toUpper());
    }
    return false;
}

/*!
 \details \~french
 \fn SH_ExtendedProxyModel::setHeaderData
*/
QVariant SH_SqlQueryModel::headerData(int section, Qt::Orientation orientation, int role)
{
    Q_UNUSED(role);
    if(orientation == Qt::Horizontal) {
        return QVariant(this->m_fields.at(section)->text());
    }
    return false;
}

/*!
 \details \~french
 \fn SH_SqlQueryModel::query
*/
const QString SH_SqlQueryModel::query() const
{
    return this->m_query.lastQuery();
}

/*!
 \details \~french
 \fn SH_SqlQueryModel::fieldsList
*/
const QStringList SH_SqlQueryModel::fieldsList() const
{
    QStringList fields;
    if(this->m_new || this->m_fields.isEmpty()) {
        int c = this->m_fields.count();
        for (int i = 0; i < c; i++)
        {
            fields.append(this->m_fields.at(i)->name());
        }
    }
    return fields;
}


/*!
 \details \~french
 \fn SH_SqlQueryModel::setFilterCondition
*/
void SH_SqlQueryModel::setFilterCondition(const QString &filter)
{
    if (this->m_condition != filter && filter != "")
    {
        this->m_condition = filter;
        emit filterConditionChanged();
    }
}

/*!
 \details \~french
 \fn SH_SqlQueryModel::fetch
*/
bool SH_SqlQueryModel::fetch()
{
    this->m_new = false;
    SH_MessageManager::debugMessage("Bienvenue dans query fetch");
    try
    {
        this->beginResetModel();
        this->m_records.clear();
        this->endResetModel();
        this->fetchQuery();
        SH_MessageManager::debugMessage(QString("query is: %1").arg(this->m_query.lastQuery()));
        bool next = this->m_query.first();

        while (next && this->m_query.isActive())
        {
            QSqlRecord record = this->m_query.record();

            SH_MessageManager::debugMessage("Nouvelle ligne récupérée");
            SH_MessageManager::debugMessage(QString("%1 champs").arg(record.count()));
            if (this->m_query.isValid() && (!record.isEmpty()) && (record.count() > 0))
            {
                this->beginInsertRows(QModelIndex(), 0, 0);
                this->m_records.append(record);
                //#ifdef DEBUGMODE
                int nbFields = record.count();
                for (int i = 0; i < nbFields; i++)
                {
                    SH_MessageManager::debugMessage(QString("%1 : %2").arg(record.fieldName(i).toUpper()).arg(record.value(i).toString()));
                }
                //#endif
                if (this->m_fields.empty())
                {
                    int nbFields = record.count();
                    for (int i = 0; i < nbFields; i++)
                    {
                        SH_SqlDataFields *field = new SH_SqlDataFields();
                        field->setName(record.fieldName(i).toUpper());
                        //SH_MessageManager::debugMessage(QString("nouveau champ (le n°%1): %2").arg(i).arg(field->name()));
                        this->m_fields.append(field);
                    }
                    this->applyRoles();
                    emit this->fieldsChanged();
                }
                this->endInsertRows();
            }
            next = this->m_query.next();
        }
    }
    catch (const std::exception &e)
    {
        SH_MessageManager::errorMessage(e.what(), "exception");
        if (this->lastError().isEmpty())
        {
            SH_MessageManager::errorMessage(this->lastError(), "erreur SQL");
        }
    }
    if (this->lastError().isEmpty())
    {
        SH_MessageManager::errorMessage(this->lastError(), "erreur SQL");
    }
    return (!this->isEmpty());
}

/*!
 \details \~french
 \fn SH_SqlQueryModel::field
*/
SH_SqlDataFields *SH_SqlQueryModel::field(int i) const
{
    i = qMin(i, this->fieldsCount()-1);
    i = qMax(i, 0);
    return this->m_fields.at(i);
}
/*!
 \details \~french
 \fn SH_SqlQueryModel::setFields
*/
void SH_SqlQueryModel::setFields(QStringList fields)
{
    fields.removeDuplicates();
    int nbFields = fields.count();
    if (nbFields > 0)
    {
        for (int i = 0; i < nbFields; i++)
        {
            SH_SqlDataFields *field = new SH_SqlDataFields();
            field->setName(fields.at(i).toUpper());
            this->m_fields.append(field);
        }
        this->applyRoles();
        emit fieldsChanged();
    }
}
/*!
 \details \~french
 \fn SH_SqlQueryModel::resetFieldsToAll
*/
void SH_SqlQueryModel::resetFieldsToAll()
{
    this->m_fields.clear();
    this->applyRoles();
    emit fieldsChanged();
}
/*!
 \details \~french
 \fn SH_SqlQueryModel::lastError
*/
const QString SH_SqlQueryModel::lastError()
{
    QSqlError error = this->m_query.lastError();
    if (error.isValid() && !error.text().isEmpty())
    {
        emit lastErrorChanged();
        return error.text();
    }
    else
    {
        return "";
    }
}
/*!
 \details \~french
 \fn SH_SqlQueryModel::applyRoles
*/
void SH_SqlQueryModel::applyRoles()
{
    if(!this->m_new) {
        this->m_roles.clear();
        int nbFields = this->m_fields.count();
        for (int i = 0; i < nbFields; i++)
        {
            this->m_roles.insert(this->roleForField(i), this->m_fields.at(i)->role());
        }
        emit rolesChanged();
    }
}


/*!
 \details \~french
 \fn SH_SqlQueryModel::fieldsCount
*/
int SH_SqlQueryModel::fieldsCount() const
{
    if(this->m_new || this->m_fields.isEmpty()) {
        return 0;
    } else {
        return this->m_fields.count();
    }
}
/*!
 \details \~french
 \fn SH_SqlQueryModel::setOrderBy
*/
void SH_SqlQueryModel::setOrderBy(QString sort)
{
    this->m_order = sort;
}
/*!
 \details \~french
 \fn SH_SqlQueryModel::isEmpty
*/
bool SH_SqlQueryModel::isEmpty() const
{
    return this->m_new || this->m_records.empty();
}


QVariant SH_SqlQueryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    //TODO SH_SqlMQueryModel headerData
    QAbstractListModel::headerData(section, orientation, role);
}
