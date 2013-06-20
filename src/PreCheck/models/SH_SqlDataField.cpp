#include "SH_SqlDataField.h"

/*!
 \brief

 \fn SqlDataFields::SqlDataFields
 \param parent
*/
SH_SqlDataFields::SH_SqlDataFields(QQuickItem *parent) :
    QQuickItem(parent)
{
    this->setHeight(15);
}

/*!
 \brief

 \fn SqlDataFields::setText
 \param newText
*/
void SH_SqlDataFields::setText(QString newText)
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
void SH_SqlDataFields::setName(QString newName)
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
void SH_SqlDataFields::setSortOrder(Qt::SortOrder newSortOrder)
{
    m_sortOrder = newSortOrder;
    emit sortOrderChanged();
}
