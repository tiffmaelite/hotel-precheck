#include "client.h"

Client::Client(int ID, QString name, QString email, QString phoneNumber, boolean isCurrentClient, QObject *parent) :
    QSqlRelationalTableModel(parent)
{
	this->unsetEmail();
this->unsetPhoneNumber();
	this->m_id = ID;
   this->setName(name);
   this->setEmail(email);
   this->setPhoneNumber(phoneNumber);
   this->becomesCurrentClient(isCurrentClient);
}

	void setName(QString name)
	{
		if(name != "") {
		this->m_name = name;
		} else {
			qWarning() << "Le nom d'un client ne peut pas être nul";
		}
	}
	
	QString name() const
	{
		return this->m_name;
	}
	
		void setEmail(QString email)
	{
	if(email != "") {
		this->m_email = email;
	}
	}
	
	QString email() const
	{
		return this->m_email;
	}
	
	void unsetEmail() {
		this->m_email = "";
	}
	
		void setPhoneNumber(QString phone)
	{
		if(phone != "") {
		this->m_phone = phone;
		}
	}
	
	QString phoneNumber() const
	{
		return this->m_phone;
	}
	
	void unsetPhoneNumber() {
		this->m_phone = "";
	}
	
		void becomesCurrentClient(boolean current)
	{
		this->m_current = current;
	}
	
	QString isCurrentClient() const
	{
		return this->m_current;
	}
