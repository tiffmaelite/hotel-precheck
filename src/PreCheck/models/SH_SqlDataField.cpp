#include "SH_SqlDataField.h"
/*namespace SimplHotel
{*/
/*!
 \details \~french
 \fn SH_SqlDataFields::SqlDataFields
*/
SH_SqlDataFields::SH_SqlDataFields(QQuickItem *parent) :
    QQuickItem(parent)
{
    this->setHeight(15);
}
/*!
 \details \~french
 \fn SH_SqlDataFields::setText
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
 \details \~french
 \fn SH_SqlDataFields::setName
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

/*}*/
