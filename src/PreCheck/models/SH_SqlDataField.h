#ifndef SQLDATAFIELDS_H
#define SQLDATAFIELDS_H

#include <QObject>
#include <QtQuick>

/*!
 \brief

 \class SqlDataFields sql_data_field.h "models/sql_data_field.h"
*/
class SH_SqlDataFields : public QQuickItem
{
        Q_OBJECT
        Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
        Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
        Q_PROPERTY(QByteArray role READ role NOTIFY roleChanged)
        Q_PROPERTY(Qt::SortOrder sortOrder READ sortOrder WRITE setSortOrder NOTIFY sortOrderChanged)
    public:

        /*!
         \brief

         \fn SqlDataFields
         \param parent
        */
        explicit SH_SqlDataFields(QQuickItem *parent = 0);

        /*!
         \brief

         \fn text
         \return QString
        */
        QString text() const { return m_text; }
        /*!
         \brief

         \fn name
         \return QString
        */
        QString name() const { return m_name; }
        /*!
         \brief

         \fn role
         \return QByteArray
        */
        QByteArray role() const { return QByteArray(m_name.toUpper().toStdString().c_str()); }
        /*!
         \brief

         \fn sortOrder
         \return Qt::SortOrder
        */
        Qt::SortOrder sortOrder() const { return m_sortOrder; }

        /*!
         \brief

         \fn setText
         \param newText
        */
        void setText(QString newText);
        /*!
         \brief

         \fn setName
         \param newName
        */
        void setName(QString newName);
        /*!
         \brief

         \fn setSortOrder
         \param newSortOrder
        */
        void setSortOrder(Qt::SortOrder newSortOrder);

    private:
        QString m_text; /*!< TODO */
        QString m_name; /*!< TODO */
        Qt::SortOrder m_sortOrder; /*!< TODO */

    signals:
        /*!
         \brief

         \fn textChanged
        */
        void textChanged();
        /*!
         \brief

         \fn nameChanged
        */
        void nameChanged();
        /*!
         \brief

         \fn roleChanged
        */
        void roleChanged();
        /*!
         \brief

         \fn sortOrderChanged
        */
        void sortOrderChanged();

    public slots:

};

#endif // SQLDATAFIELDS_H
