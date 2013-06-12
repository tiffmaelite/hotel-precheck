#include "SqlDataModel.h"
#include <QDir>
#include <QDebug>
#include "database_manager.h"
#include "views/message_manager.h"
#include <QtSql/QSqlDriver>

SqlDataModel::SqlDataModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

int SqlDataModel::rowCount(const QModelIndex &parent) const
{
    return mRecords.count();
}


QVariant SqlDataModel::data(const QModelIndex &index, int role) const
{
    if (this->mRecords.count() > 0)
    {
        int row = index.row();
        int column = this->fieldFromRole(role);
        int nbCols = this->mRoles.count();
        if(column >= 0 && column < nbCols) {
            //MessageManager::infoMessage(QString("row : %1, column : %2, field: %3 (%4), value : %5\n").arg(index.row()).arg(index.column()).arg(column).arg(QString(this->mDataFields.at(column)->role())).arg(this->mRecords.at(row).value(column).toString()));
            return this->mRecords.at(row).value(column);
        } else{
            //MessageManager::errorMessage(QString("rien à retourner pour %1x%2x%3 (%4>=%5)").arg(index.row()).arg(index.column()).arg(role).arg(column).arg(nbCols));
        }
    }
    //MessageManager::errorMessage("modèle vide");
    return QVariant();
}

bool SqlDataModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    Q_UNUSED(role);
    if (orientation == Qt::Horizontal)
    {
        this->mDataFields.at(section)->setText(value.toString());
        return (this->mDataFields.at(section)->text() == value.toString());
    }
    return false;
}

void SqlDataModel::setQuery(const QString &query)
{
    try
    {
        QString cleanQuery = query.simplified();//.toUpper();
        //MessageManager::infoMessage("REQUÊTE : " + cleanQuery);
        beginResetModel();
        mRecords.clear();
        endResetModel();
        mSqlQuery = QSqlQuery(AppDatabase::getInstance()->getDbConnection());
        if (mSqlQuery.exec(cleanQuery) && (!AppDatabase::getInstance()->getDbConnection().driver()->hasFeature(QSqlDriver::QuerySize) || mSqlQuery.size() > 0))
        {
            bool next = mSqlQuery.next();
            while (next && mSqlQuery.isActive())
            {
                QSqlRecord record = mSqlQuery.record();
                /*qDebug() << "\n\n";
                MessageManager::infoMessage("Nouvelle ligne récupérée");
                MessageManager::infoMessage(QString("%1 champs").arg(record.count()));*/
                if ((!record.isEmpty()) && (record.count() > 0))
                {
                    beginInsertRows(QModelIndex(), 0, 0);
                    mRecords.append(record);
                    /*int nbFields = record.count();
                    for (int i = 0; i < nbFields; i++)
                    {
                        MessageManager::infoMessage(QString("%1 : %2").arg(record.fieldName(i)).arg(record.value(i).toString()));
                    }*/
                    if (mDataFields.empty())
                    {
                        int nbFields = record.count();
                        for (int i = 0; i < nbFields; i++)
                        {
                            SqlDataFields *field = new SqlDataFields();
                            field->setName(record.fieldName(i));
                            //MessageManager::infoMessage(QString("nouveau champ (le n°%1): %2").arg(i).arg(field->name()));
                            mDataFields.append(field);
                        }
                        this->applyRoles();
                        emit fieldsChanged();
                    }
                    endInsertRows();
                }
                next = mSqlQuery.next();
            }
        }
    }
    catch (const std::exception &e)
    {
        MessageManager::errorMessage(e.what(), "exception");
        if (this->lastError().isEmpty())
        {
            MessageManager::errorMessage(this->lastError(), "erreur SQL");
        }
    }
    if (this->lastError().isEmpty())
    {
        MessageManager::errorMessage(this->lastError(), "erreur SQL");
    }
}


const QString &SqlDataModel::query()
{
    return mSqlQuery.lastQuery();
}

const QString &SqlDataModel::tableName()
{
    return mTable;
}

const QString &SqlDataModel::filter()
{
    return mFilter;
}

const QString SqlDataModel::fieldsList()
{
    if (mDataFields.empty())
    {
        return "*";
    }
    else
    {
        QString fields = this->mDataFields.at(0)->name();
        int c = mDataFields.count();
        for (int i = 1; i < c; i++)
        {
            fields += ", " + this->mDataFields.at(i)->name();
        }
        return QString(" %1 ").arg(fields);
    }
}

void SqlDataModel::setTable(const QString &tableName)
{
    if (mTable.toUpper() != tableName.toUpper() && tableName != "")
    {
        mTable = tableName.toUpper();
        emit tableChanged();
    }
}

void SqlDataModel::setFilterCondition(const QString &filter)
{
    if (mFilter != filter && filter != "")
    {
        mFilter = filter;
        emit filterChanged();
    }
}

void SqlDataModel::resetFilterCondition()
{
    mFilter = "";
    emit filterChanged();
}

bool SqlDataModel::fetch(QString tableName, QString filter, QString sort, QStringList fieldsList)
{
    this->setFields(fieldsList);
    this->setTable(tableName);
    this->setFilterCondition(filter);
    this->setOrderBy(sort);

    QString condition = "";
    if (this->mFilter != "")
    {
        condition = " WHERE " + this->mFilter;
    }
    QString order = "";
    if (this->mSort != "")
    {
        order = " ORDER BY " + this->mSort;
    }
    QString f = this->fieldsList();
    this->setQuery(QString("SELECT %1 FROM %2 %3 %4").arg(f).arg(mTable).arg(condition).arg(order));
    return (!this->isEmpty());
}

SqlDataFields *SqlDataModel::field(int i)
{
    i = qMin(i, this->fieldsCount()-1);
    i = qMax(i, 0);
    return this->mDataFields.at(i);
}

void SqlDataModel::setFields(QStringList fields)
{
    fields.removeDuplicates();
    int nbFields = fields.count();
    if (nbFields > 0)
    {
        for (int i = 0; i < nbFields; i++)
        {
            SqlDataFields *field = new SqlDataFields();
            field->setName(fields.at(i));
            mDataFields.append(field);
        }
        this->applyRoles();
        emit fieldsChanged();
    }
}

void SqlDataModel::resetFieldsToAll()
{
    mDataFields.clear();
    this->applyRoles();
    emit fieldsChanged();
}

const QString &SqlDataModel::lastError()
{
    QSqlError error = mSqlQuery.lastError();
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


void SqlDataModel::applyRoles()
{
    this->mRoles.clear();
    int nbFields = this->mDataFields.count();
    for (int i = 0; i < nbFields; i++)
    {
        //MessageManager::infoMessage(QString("nouveau rôle : %1").arg(QString(this->mDataFields.at(i)->role())));
        this->mRoles.insert(this->roleForField(i), this->mDataFields.at(i)->role());
    }
    emit rolesChanged();
}


int SqlDataModel::fieldsCount()
{
    return mDataFields.count();
}

void SqlDataModel::setOrderBy(QString sort)
{
    this->mSort = sort;
}

bool SqlDataModel::isEmpty()
{
    return mRecords.empty();
}
