#ifndef SQLDATAFIELDS_H
#define SQLDATAFIELDS_H

#include <QObject>
#include <QtQuick>

/*!
\brief \~french 

 \class SH_SqlDataFields sql_data_field.h "models/sql_data_field.h"
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
        \brief \~french 

         \fn SH_SqlDataFields
         \param parent
        */
        explicit SH_SqlDataFields(QQuickItem *parent = 0);

        /*!
        \brief \~french 

         \fn SH_text
         \return QString
        */
        QString text() const { return m_text; }
        /*!
        \brief \~french 

         \fn SH_name
         \return QString
        */
        QString name() const { return m_name; }
        /*!
        \brief \~french 

         \fn SH_role
         \return QByteArray
        */
        QByteArray role() const { return QByteArray(m_name.toUpper().toStdString().c_str()); }
        /*!
        \brief \~french 

         \fn SH_sortOrder
         \return Qt::SortOrder
        */
        Qt::SortOrder sortOrder() const { return m_sortOrder; }

        /*!
        \brief \~french 

         \fn SH_setText
         \param newText
        */
        void setText(QString newText);
        /*!
        \brief \~french 

         \fn SH_setName
         \param newName
        */
        void setName(QString newName);
        /*!
        \brief \~french 

         \fn SH_setSortOrder
         \param newSortOrder
        */
        void setSortOrder(Qt::SortOrder newSortOrder);

    private:
        /*!
         *\brief \~french  m_text
         */
        QString m_text;
        /*!
         *\brief \~french  m_name
         */
        QString m_name;
        /*!
         *\brief \~french  m_sortOrder
         */
        Qt::SortOrder m_sortOrder;

    signals:
        /*!
        \brief \~french 

         \fn SH_textChanged
        */
        void textChanged();
        /*!
        \brief \~french 

         \fn SH_nameChanged
        */
        void nameChanged();
        /*!
        \brief \~french 

         \fn SH_roleChanged
        */
        void roleChanged();
        /*!
        \brief \~french 

         \fn SH_sortOrderChanged
        */
        void sortOrderChanged();

    public slots:

};

#endif /* SQLDATAFIELDS_H*/
