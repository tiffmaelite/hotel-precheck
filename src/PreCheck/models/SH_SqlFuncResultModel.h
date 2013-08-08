#ifndef SH_SQLFUNCRESULTMODEL_H
#define SH_SQLFUNCRESULTMODEL_H
#include "SH_SqlQueryModel.h"

class SH_SqlFuncResultModel : public SH_SqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString functionCall READ functionCall WRITE setFunctionCall NOTIFY functionCallChanged) //MEMBER m_functionCall
public:
    explicit SH_SqlFuncResultModel(QObject *parent = 0);
    void setFunctionCall(const QString &functionCall);
    void fetchQuery();
    void fetchQuery(QString functionCall);
    QString functionCall() const { return this->m_functionCall; }

signals:

    /*!
    \brief \~french
    \fn tableNameChanged
    */
    void functionCallChanged();

private:
    /*!
    *\brief \~french mTable
    */
    QString m_functionCall;
};

#endif // SH_SQLFUNCRESULTMODEL_H
