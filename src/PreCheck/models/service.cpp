#include "service.h"

Service::Service(QString name, QString email, QString phoneNumber, boolean isCurrentService, QObject *parent = 0);
    QSqlRelationalTableModel(parent)
{
   this->setName(name);
   this->setEmail(email);
   this->setPhoneNumber(phoneNumber);
   this->becomesCurrentService(isCurrentService);
}

	void setName(QString name)
	{
		m_name = name;
	}
	
	QString name() const
	{
		return m_name;
	}
	
		void setEmail(QString email)
	{
		m_email = email;
	}
	
	QString email() const
	{
		return m_email;
	}
	
	void unsetEmail() {
		m_email = "";
	}
	
		void setPhoneNumber(QString phone)
	{
		m_phone = phone;
	}
	
	QString phoneNumber() const
	{
		return m_phone;
	}
	
	void unsetPhoneNumber() {
		m_phone = "";
	}
	
		void becomesCurrentService(boolean current)
	{
		m_current = current;
	}
	
	QString isCurrentService() const
	{
		return m_current;
	}
