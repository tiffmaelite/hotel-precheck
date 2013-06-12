#ifndef SERVICE_H
#define SERVICE_H

class Service : public QSqlRelationalTableModel
{
    Q_OBJECT
	Q_PROPERTY(QString id READ ID);
	Q_PROPERTY(QString name READ name);
	Q_PROPERTY(QString email READ email WRITE setEmail RESET unsetEmail);
	Q_PROPERTY(QString phone READ phoneNumber WRITE setPhoneNumber RESET unsetPhoneNumber);
	Q_PROPERTY(boolean currentService READ isCurrentService WRITE becomesCurrentService
		
public:
    Service(QString name, QString email = "", QString phoneNumber = "", boolean isCurrentService = true, QObject *parent = 0);
	
	void setEmail(QString email);
	QString email() const;
	void unsetEmail();
	QString name const;
	void setPhoneNumber(QString phoneNumber);
	QString phoneNumber() const;
	void unsetPhoneNumber();
	void becomesCurrentService(boolean isCurrentService);
	boolean isCurrentService() const;
		
	private:
	void setName(QString name);
	QString m_email;
	QString m_phone;
	boolean m_current;
	QString m_name;
};

#endif // SERVICE_H
