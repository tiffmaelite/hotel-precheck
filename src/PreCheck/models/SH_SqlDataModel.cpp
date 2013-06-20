#include <QDir>
#include <QDebug>
#include <QtSql/QSqlDriver>
#include <QtCore>
#include "SH_SqlDataModel.h"
#include "SH_DatabaseManager.h"
#include "SH_MessageManager.h"


/*!
 \brief

 \fn SqlDataModel::SqlDataModel
 \param parent
*/
SH_SqlDataModel::SH_SqlDataModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

/*!
 \brief

 \fn SqlDataModel::rowCount
 \param parent
 \return int
*/
int SH_SqlDataModel::rowCount(const QModelIndex &parent) const
{
    return mRecords.count();
}


/*!
 \brief

 \fn SqlDataModel::data
 \param index
 \param role
 \return QVariant
*/
QVariant SH_SqlDataModel::data(const QModelIndex &index, int role) const
{
    if (this->mRecords.count() > 0)
    {
        int row = index.row();
        int column = this->fieldFromRole(role);
        int nbCols = this->mRoles.count();
        if(column >= 0 && column < nbCols) {
            SH_MessageManager::infoMessage(QString("row : %1, column : %2, field: %3 (%4), value : %5\n").arg(index.row()).arg(index.column()).arg(column).arg(QString(this->mDataFields.at(column)->role())).arg(this->mRecords.at(row).value(column).toString()));
            return this->mRecords.at(row).value(column);
        } else{
            SH_MessageManager::errorMessage(QString("rien à retourner pour %1x%2x%3 (%4>=%5)").arg(index.row()).arg(index.column()).arg(role).arg(column).arg(nbCols));
        }
    }
    SH_MessageManager::errorMessage("modèle vide");
    return QVariant();
}

/*!
 \brief
 \fn SqlDataModel::datas TODO comment this
 \return QVariantMap TODO comment this
*/
QVariantMap SH_SqlDataModel::datas() const
{
    qDebug() << "datas";
    QVariantMap result;
    if (this->mRecords.count() > 0)
    {
        qDebug() << "datas ok";
        for(int column = 0; column < this->mRoles.count(); column++) {
            for(int row = 0; row < this->mRecords.count();row++) {
                qDebug() << "data inserted";
                result.insertMulti(this->mRoles.value(column),this->mRecords.at(row).value(column));
            }
        }
    }
    return result;
}

/*!
 \brief

 \fn SqlDataModel::setHeaderData
 \param section
 \param orientation
 \param value
 \param role
 \return bool
*/
bool SH_SqlDataModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    Q_UNUSED(role);
    if (orientation == Qt::Horizontal)
    {
        this->mDataFields.at(section)->setText(value.toString());
        return (this->mDataFields.at(section)->text() == value.toString());
    }
    return false;
}
/*!
 \brief

 \fn SqlDataModel::query
 \return const QString
*/
const QString &SH_SqlDataModel::query() const
{
    return mSqlQuery.lastQuery();
}

/*!
 \brief

 \fn SqlDataModel::tableName
 \return const QString
*/
const QString &SH_SqlDataModel::tableName() const
{
    return mTable;
}

/*!
 \brief

 \fn SqlDataModel::filter
 \return const QString
*/
const QString &SH_SqlDataModel::filter() const
{
    return mFilter;
}

/*!
 \brief

 \fn SqlDataModel::fieldsList
 \return const QString
*/
const QStringList SH_SqlDataModel::fieldsList() const
{
    QStringList fields;
    if(!this->mDataFields.isEmpty()) {
        int c = mDataFields.count();
        for (int i = 0; i < c; i++)
        {
            fields .append(this->mDataFields.at(i)->name());
        }
    }
    return fields;
}

/*!
 \brief

 \fn SqlDataModel::setTable
 \param tableName
*/
void SH_SqlDataModel::setTable(const QString &tableName)
{
    if (mTable.toUpper() != tableName.toUpper() && tableName != "")
    {
        mTable = tableName.toUpper();
        emit tableChanged();
    }
}

/*!
 \brief

 \fn SqlDataModel::setFilterCondition
 \param filter
*/
void SH_SqlDataModel::setFilterCondition(const QString &filter)
{
    if (mFilter != filter && filter != "")
    {
        mFilter = filter;
        emit filterChanged();
    }
}

/*!
 \brief

 \fn SqlDataModel::resetFilterCondition
*/
void SH_SqlDataModel::resetFilterCondition()
{
    mFilter = "";
    emit filterChanged();
}

/*!
 \brief

 \fn SqlDataModel::fetch
 \param tableName
 \param filter
 \param sort
 \param fieldsList
 \return bool
*/
bool SH_SqlDataModel::fetch(QString tableName, QString filter, QString sort, QStringList fieldsList)
{
    if(!mTable.isEmpty() || !tableName.isEmpty()) {
        SH_MessageManager::infoMessage("Bienvenue dans fetch");
        qDebug() << mTable << " " << this->fieldsList().join(", ") << " " << mFilter << " " << mSort;
        this->setFields(fieldsList);
        this->setTable(tableName);
        this->setFilterCondition(filter);
        this->setOrderBy(sort);
        qDebug() << tableName << " " << filter << " " << sort << " " << fieldsList.join(", ");
        try
        {
            beginResetModel();
            mRecords.clear();
            endResetModel();
            qDebug() << mTable << " " << this->fieldsList() << " " << mFilter << " " << mSort;
            mSqlQuery = SH_DatabaseManager::getInstance()->execSelectQuery(mTable, this->fieldsList(), mFilter, mSort);
            qDebug() << mSqlQuery.executedQuery();
            bool next = mSqlQuery.next();
            if(next) {
                qDebug() << "next ok";
            }
            while (next) // && mSqlQuery.isActive())
            {
                QSqlRecord record = mSqlQuery.record();
                qDebug() << "\n\n";
                SH_MessageManager::infoMessage("Nouvelle ligne récupérée");
                SH_MessageManager::infoMessage(QString("%1 champs").arg(record.count()));
                if (mSqlQuery.isValid() && (!record.isEmpty()) && (record.count() > 0))
                {
                    beginInsertRows(QModelIndex(), 0, 0);
                    mRecords.append(record);
                    int nbFields = record.count();
                    for (int i = 0; i < nbFields; i++)
                    {
                        SH_MessageManager::infoMessage(QString("%1 : %2").arg(record.fieldName(i)).arg(record.value(i).toString()));
                    }
                    if (mDataFields.empty())
                    {
                        int nbFields = record.count();
                        for (int i = 0; i < nbFields; i++)
                        {
                            SH_SqlDataFields *field = new SH_SqlDataFields();
                            field->setName(record.fieldName(i));
                            SH_MessageManager::infoMessage(QString("nouveau champ (le n°%1): %2").arg(i).arg(field->name()));
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
    }
    return (!this->isEmpty());
}

/*!
 \brief

 \fn SqlDataModel::field
 \param i
 \return SqlDataFields
*/
SH_SqlDataFields *SH_SqlDataModel::field(int i) const
{
    i = qMin(i, this->fieldsCount()-1);
    i = qMax(i, 0);
    return this->mDataFields.at(i);
}

/*!
 \brief

 \fn SqlDataModel::setFields
 \param fields
*/
void SH_SqlDataModel::setFields(QStringList fields)
{
    fields.removeDuplicates();
    int nbFields = fields.count();
    if (nbFields > 0)
    {
        for (int i = 0; i < nbFields; i++)
        {
            SH_SqlDataFields *field = new SH_SqlDataFields();
            field->setName(fields.at(i));
            mDataFields.append(field);
        }
        this->applyRoles();
        emit fieldsChanged();
    }
}

/*!
 \brief

 \fn SqlDataModel::resetFieldsToAll
*/
void SH_SqlDataModel::resetFieldsToAll()
{
    mDataFields.clear();
    this->applyRoles();
    emit fieldsChanged();
}

/*!
 \brief

 \fn SqlDataModel::lastError
 \return const QString
*/
const QString &SH_SqlDataModel::lastError()
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


/*!
 \brief

 \fn SqlDataModel::applyRoles
*/
void SH_SqlDataModel::applyRoles()
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


/*!
 \brief

 \fn SqlDataModel::fieldsCount
 \return int
*/
int SH_SqlDataModel::fieldsCount() const
{
    return mDataFields.count();
}

/*!
 \brief

 \fn SqlDataModel::setOrderBy
 \param sort
*/
void SH_SqlDataModel::setOrderBy(QString sort)
{
    this->mSort = sort;
}

/*!
 \brief

 \fn SqlDataModel::isEmpty
 \return bool
*/
bool SH_SqlDataModel::isEmpty() const
{
    return mRecords.empty();
}
