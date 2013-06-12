#include "PreCheckThread.h"
#include <QtSql>
#include "models/database_manager.h"

PreCheckThread::PreCheckThread(QObject *parent) :
    QThread(parent)
{
    this->currentStep = 0;
}

bool PreCheckThread::insertUpdateDatabase(QString tableName)
{
    if(!content.isEmpty()) {
        QString fieldsList;
        QString valuesList;
        for(QVariantMap::const_iterator iter = content.begin(); iter != content.end(); ++iter) {
            QVariant val = iter.value();
            if(val.isValid()) {
                fieldsList+=", "+iter.key();
                valuesList+=", ";
                bool ok;
                int  intVal = val.toInt(&ok);
                if(ok) {
                    valuesList+=intVal;
                } else {
                    float floatVal = val.toFloat(&ok);
                    if(ok) {
                        valuesList+=floatVal;
                    } else {
                        double doubleVal = val.toDouble(&ok);
                        if(ok) {
                            valuesList+=doubleVal;
                        }
                    }
                }
                valuesList+="'"+iter.value().toString()+"'";
            }
        }
        if(!valuesList.isEmpty() && !fieldsList.isEmpty()) {
            QSqlQuery* insertQuery = new QSqlQuery(AppDatabase::getInstance()->getDbConnection());
            return insertQuery->exec("INSERT INTO "+tableName+"("+fieldsList.right(fieldsList.size()-2)+") VALUES("+valuesList.right(valuesList.size()-2)+")");
        }
    }
    return false;
}


void PreCheckThread::replaceInput(QString field)
{
    this->toBeReplaced = field;
}

void PreCheckThread::cancelReplacement()
{
    this->toBeReplaced = "";
}
