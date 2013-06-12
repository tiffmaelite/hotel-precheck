#include "booking.h"

Booking::Booking(QString name, QString email, QString phoneNumber, boolean isCurrentBooking, QObject *parent = 0);
    QSqlRelationalTableModel(parent)
{
   this->setName(name);
   this->setEmail(email);
   this->setPhoneNumber(phoneNumber);
   this->becomesCurrentBooking(isCurrentBooking);
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
	
		void becomesCurrentBooking(boolean current)
	{
		m_current = current;
	}
	
	QString isCurrentBooking() const
	{
		return m_current;
	}
