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
    this->m_text = newText;
    if (this->m_name == "")
    {
        this->setName(this->m_text);
    }
    emit textChanged();
}
/*!
 \details \~french
 \fn SH_SqlDataFields::setName
*/
void SH_SqlDataFields::setName(QString newName)
{
    this->m_name = newName.toUpper();
    this->setSortOrder(Qt::AscendingOrder);
    if (this->m_text == "")
    {
        this->setText(this->m_name.toLower());
    }
    emit nameChanged();
    emit roleChanged();
}

/*}*/
