#include "client.h"

#ifndef GROUP_H
#define GROUP_H

class Group : public QSqlRelationalTableModel
{
    Q_OBJECT
	Q_PROPERTY(QString name READ name);
	Q_PROPERTY(Client contact1 READ contact1 WRITE setContact1 RESET unsetContact1);
	Q_PROPERTY(Client contact2 READ contact2 WRITE setContact2 RESET unsetContact2);
	Q_PROPERTY(Client contact3 READ contact3 WRITE setContact3 RESET unsetContact3);
		
public:
    Group(int ID, QString name, Client* clients, Client contact1 = NULL, Client contact2 = NULL, Client contact3 = NULL, QObject *parent = 0);
	
	Client* clientsList();
	void addClient(Client client);
	void addContact(Client contact);
	void setContact1(Client contact);
	Client contact1() const;
	void unsetContact1();
	void setContact2(Client contact);
	Client contact2() const;
	void unsetContact2();
	void setContact3(Client contact);
	Client contact3() const;
	void unsetContact3();
		
	protected:
	void setClients(Client* list);
	void addClients(Client* list);
private:
	void setName(QString name);
	Client m_contact1;
	Client m_contact2;
	Client m_contact3;
	Client* m_clients;
	int m_id;
};

#endif // GROUP_H
