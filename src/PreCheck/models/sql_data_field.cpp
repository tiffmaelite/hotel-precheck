#include "sql_data_field.h"


/*!
 \brief

 \fn SqlDataFields::SqlDataFields
 \param parent
*/
SqlDataFields::SqlDataFields(QQuickItem *parent) :
    QQuickItem(parent)
{
    this->setHeight(15);
}

/*!
 \brief

 \fn SqlDataFields::setText
 \param newText
*/
void SqlDataFields::setText(QString newText)
{
    m_text = newText;
    if (m_name == "")
    {
        this->setName(m_text.toUpper());
    }
    emit textChanged();
}

/*!
 \brief

 \fn SqlDataFields::setName
 \param newName
*/
void SqlDataFields::setName(QString newName)
{
    m_name = newName;
    this->setSortOrder(Qt::AscendingOrder);
    if (m_text == "")
    {
        this->setText(m_name);
    }
    emit nameChanged();
    emit roleChanged();
}


/*!
 \brief

 \fn SqlDataFields::setSortOrder
 \param newSortOrder
*/
void SqlDataFields::setSortOrder(Qt::SortOrder newSortOrder)
{
    m_sortOrder = newSortOrder;
    emit sortOrderChanged();
}
