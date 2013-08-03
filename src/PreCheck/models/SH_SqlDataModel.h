#ifndef SQLDATAMODEL_H
#define SQLDATAMODEL_H
#include "SH_SqlQueryModel.h"
/*namespace SimplHotel
{*/
/*!
\brief \~french
 \class SH_SqlDataModel SqlDataModel.h "models/SqlDataModel.h"
*/
class SH_SqlDataModel : public SH_SqlQueryModel
{
    Q_OBJECT
    Q_PROPERTY(QString tableName READ tableName WRITE setTableName NOTIFY tableNameChanged) //MEMBER m_tableName


public:

    /*!
    \brief \~french
    \fn SqlDataModel
    \param parent
    */
    explicit SH_SqlDataModel(QObject *parent = 0);

    /*!
    * \fn tableName
    * \brief \~french Accesseur en lecture de la propriété \a choiceList
    * \details \~french Permet d'obtenir la liste de choix permis dans cet état
    * \return QString La liste de choix de l'état
    */
    QString tableName() const { return m_tableName; }
    /*!
    * \fn setTableName
    * \brief \~french Accesseur en écriture de la propriété \a choiceList
    * \details \~french Permet de définir la liste de choix permis dans cet état
    * \param QString table La nouvelle liste de choix de l'état
    */
    void setTableName(const QString &table);



    /*!
    \brief \~french
    \fn fetchQuery
    \param tableName
    \param filter
    \param sort
    \param fields
    */
    void fetchQuery(QString tableName, QString filter = "", QString sort="", QStringList fields = QStringList());


    void fetchQuery();
signals:

    /*!
    \brief \~french
    \fn tableNameChanged
    */
    void tableNameChanged();

  private:
    /*!
    *\brief \~french mTable
    */
    QString m_tableName;


};
/*}*/
#endif /* SQLDATAMODEL_H*/
