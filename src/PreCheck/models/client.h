#ifndef CLIENT_H
#define CLIENT_H

class Client : public QSqlRelationalTableModel
{
    Q_OBJECT
	Q_PROPERTY(QString name READ name);
	Q_PROPERTY(QString email READ email WRITE setEmail RESET unsetEmail);
	Q_PROPERTY(QString phone READ phoneNumber WRITE setPhoneNumber RESET unsetPhoneNumber);
	Q_PROPERTY(boolean currentClient READ isCurrentClient WRITE becomesCurrentClient);
		
public:
    Client(int ID, QString name, QString email = "", QString phoneNumber = "", boolean isCurrentClient = true, QObject *parent = 0);
	
	void setEmail(QString email);
	QString email() const;
	void unsetEmail();
	QString name const;
	void setPhoneNumber(QString phoneNumber);
	QString phoneNumber() const;
	void unsetPhoneNumber();
	void becomesCurrentClient(boolean isCurrentClient);
	boolean isCurrentClient() const;
		
	private:
	void setName(QString name);
	QString m_email;
	QString m_phone;
	boolean m_current;
	QString m_name;
	int m_id;
};

#endif // CLIENT_H
