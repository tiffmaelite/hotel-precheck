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
    Q_PROPERTY(QString name MEMBER m_name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString text MEMBER m_text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QByteArray role READ role NOTIFY roleChanged)
    Q_PROPERTY(Qt::SortOrder sortOrder MEMBER m_sortOrder NOTIFY sortOrderChanged)
    public:

/*!
    \brief \~french
    \fn SH_SqlDataFields
    \param parent
    */
    explicit SH_SqlDataFields(QQuickItem *parent = 0);

/*!
    \brief \~french
    \fn role
    \return QByteArray
    */
    QByteArray role() const { return QByteArray(m_name.toUpper().toStdString().c_str()); }
    void setText(QString newText);
    void setName(QString newName);
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
