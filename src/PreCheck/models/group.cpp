#include "group.h"

    Group::Group(int ID, QString name, Client* clients, Client contact1, Client contact2, Client contact3, QObject *parent)  :
QSqlRelationalTableModel(parent) {
	this->m_id = ID;
	this->setName(name);
	this->unsetContact1();
	this->unsetContact2();
	this->unsetContact3();
	this->addContact(contact1);
	this->addContact(contact2);
	this->addContact(contact3);
	this->setClients(clients);
	}
	
	Client* Group::clientsList() {
		return this->m_clients;
	}
	
	void Group::addClient(Client client) {
		//TODO Group::addClient
	}
	
	void Group::addContact(Client contact) {
	if(this->contact1() == NULL) {
	this->setContact1(contact);
	} else 	if(this->contact2() == NULL) {
		this->setContact2(contact);
		} else {
			this->setContact3(contact);
		}
	}
	
	void Group::setContact1(Client contact) {
	if(contact != NULL) {
		this->m_contact1 = contact;
	}
	}
	
	Client Group::contact1() const {
		return this->m_contact1;
	}
	
	void Group::unsetContact1() {
		this->contact1 = NULL;
	}
	
	void Group::setContact2(Client contact) {
		if(contact != NULL) {
			this->m_contact2 = contact;
		}
	}
	
	Client Group::contact2() const {
		return this->m_contact2;
	}
	
	void Group::unsetContact2() {
		this->contact2 = NULL;
	}
	
	void Group::setContact3(Client contact) {
		if(contact != NULL) {
			this->m_contact3 = contact;
		}
	}
	
	Client Group::contact3() const {
		return this->m_contact3;
	}
	
	void Group::unsetContact3() {
		this->contact3 = NULL;
	}

	void Group::setClients(Client* list) {
		//TODO Group::setClients
	}
	
	void Group::addClients(Client* list) {
		//TODO Group::addClients
	}

	void Group::setName(QString name) {
	if(name != "") {
		this->m_name = name;
		} else {
			qWarning() << "Le nom d'un groupe ne peut pas être vide";
		}
	}