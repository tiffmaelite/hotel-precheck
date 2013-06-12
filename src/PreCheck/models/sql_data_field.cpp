#include "sql_data_field.h"


SqlDataFields::SqlDataFields(QQuickItem *parent) :
    QQuickItem(parent)
{
    this->setHeight(15);
}

void SqlDataFields::setText(QString newText)
{
    m_text = newText;
    if (m_name == "")
    {
        this->setName(m_text.toUpper());
    }
    emit textChanged();
}

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


void SqlDataFields::setSortOrder(Qt::SortOrder newSortOrder)
{
    m_sortOrder = newSortOrder;
    emit sortOrderChanged();
}
