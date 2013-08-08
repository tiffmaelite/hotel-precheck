#ifndef SQLDATAFIELDS_H
#define SQLDATAFIELDS_H
#include <QObject>
#include <QtQuick>
/*namespace SimplHotel
{*/
/*!
\brief \~french
 \class SH_SqlDataFields sql_data_field.h "models/sql_data_field.h"
*/
class SH_SqlDataFields : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged) //MEMBER m_name
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged) //MEMBER m_text
    Q_PROPERTY(QByteArray role READ role NOTIFY roleChanged)
    Q_PROPERTY(Qt::SortOrder sortOrder READ sortOrder WRITE setSortOrder NOTIFY sortOrderChanged) //MEMBER m_sortOrder

public:

    /*!
    \brief \~french
    \fn SH_SqlDataFields
    \param parent
    */
    explicit SH_SqlDataFields(QQuickItem *parent = 0);

    QString text() const { return this->m_text; }
    void setText(QString newText);
    QString name() const { return this->m_name; }
void setName(QString newName);
    /*!
    \brief \~french
    \fn role
    \return QByteArray
    */
    QByteArray role() const { return QByteArray().append(this->m_name.toUpper()); }
    void setSortOrder(Qt::SortOrder newOrder) { this->m_sortOrder = newOrder; emit sortOrderChanged();}
    Qt::SortOrder sortOrder() { return this->m_sortOrder; }

private:

    /*!
    *\brief \~french m_text
    */
    QString m_text;

    /*!
    *\brief \~french m_name
    */
    QString m_name;

    /*!
    *\brief \~french m_sortOrder
    */
    Qt::SortOrder m_sortOrder;
signals:

    /*!
    \brief \~french
    \fn textChanged
    */
    void textChanged();

    /*!
    \brief \~french
    \fn nameChanged
    */
    void nameChanged();

    /*!
    \brief \~french
    \fn roleChanged
    */
    void roleChanged();

    /*!
    \brief \~french
    \fn sortOrderChanged
    */
    void sortOrderChanged();
public slots:
};
/*}*/
#endif /* SQLDATAFIELDS_H*/
