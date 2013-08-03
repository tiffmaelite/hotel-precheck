#include "SH_SqlFuncResultModel.h"
#include "SH_DatabaseManager.h"
#include "SH_MessageManager.h"

SH_SqlFuncResultModel::SH_SqlFuncResultModel(QObject *parent): SH_SqlQueryModel(parent)
{
}


/*!
 \details \~french
 \fn SH_SqlDataModel::setTableName
*/
void SH_SqlFuncResultModel::setFunctionCall(const QString &functionCall)
{
    if (m_functionCall.toUpper() != functionCall.toUpper() && functionCall != "")
    {
        m_functionCall = functionCall.toUpper();
        emit functionCallChanged();
    }
}

void SH_SqlFuncResultModel::fetchQuery()
{
    this->fetchQuery("");
}


/*!
 \details \~french
 \fn SH_SqlDataModel::fetchQuery
*/
void SH_SqlFuncResultModel::fetchQuery(QString functionCall)
{
    if(!m_functionCall.isEmpty() || !functionCall.isEmpty()) {
        SH_MessageManager::debugMessage("Bienvenue dans fetch");
        this->setFunctionCall(functionCall);
        m_query = SH_DatabaseManager::getInstance()->getDbConnection().exec(QString("SELECT %1;").arg(m_functionCall));
    }
}
/*}*/
