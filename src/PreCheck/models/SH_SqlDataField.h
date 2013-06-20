#ifndef SQLDATAFIELDS_H
#define SQLDATAFIELDS_H

#include <QObject>
#include <QtQuick>

/*!
 \brief

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
         \brief

         \fn SH_SqlDataFields
         \param parent
        */
        explicit SH_SqlDataFields(QQuickItem *parent = 0);

        /*!
         \brief

         \fn SH_text
         \return QString
        */
        QString text() const { return m_text; }
        /*!
         \brief

         \fn SH_name
         \return QString
        */
        QString name() const { return m_name; }
        /*!
         \brief

         \fn SH_role
         \return QByteArray
        */
        QByteArray role() const { return QByteArray(m_name.toUpper().toStdString().c_str()); }
        /*!
         \brief

         \fn SH_sortOrder
         \return Qt::SortOrder
        */
        Qt::SortOrder sortOrder() const { return m_sortOrder; }

        /*!
         \brief

         \fn SH_setText
         \param newText
        */
        void setText(QString newText);
        /*!
         \brief

         \fn SH_setName
         \param newName
        */
        void setName(QString newName);
        /*!
         \brief

         \fn SH_setSortOrder
         \param newSortOrder
        */
        void setSortOrder(Qt::SortOrder newSortOrder);

    private:
        /*!
         * \brief m_text
         */
        QString m_text;
        /*!
         * \brief m_name
         */
        QString m_name;
        /*!
         * \brief m_sortOrder
         */
        Qt::SortOrder m_sortOrder;

    signals:
        /*!
         \brief

         \fn SH_textChanged
        */
        void textChanged();
        /*!
         \brief

         \fn SH_nameChanged
        */
        void nameChanged();
        /*!
         \brief

         \fn SH_roleChanged
        */
        void roleChanged();
        /*!
         \brief

         \fn SH_sortOrderChanged
        */
        void sortOrderChanged();

    public slots:

};

#endif /* SQLDATAFIELDS_H*/
