#ifndef USER_H
#define USER_H
#include <QSqlRecord>
#include <QSqlDriver>
#include <QtCore>

/*namespace SimplHotel
{*/
/*!
\brief \~french

 \class SH_User
\headerfile user.h "models/user.h"
*/
class SH_User : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int id READ id)
	Q_PROPERTY(QString name READ name NOTIFY nameChanged)
	Q_PROPERTY(bool receptionist READ isReceptionist NOTIFY rolesChanged)
	Q_PROPERTY(bool managerX READ isManagerX NOTIFY rolesChanged)
	Q_PROPERTY(bool managerZ READ isManagerZ NOTIFY rolesChanged)
	Q_PROPERTY(bool administrator READ isAdministrator NOTIFY rolesChanged)
	Q_PROPERTY(int roles READ roles NOTIFY rolesChanged)
	Q_PROPERTY(bool valid READ isValid NOTIFY validityChanged)

public:
	
/*!
\brief \~french

 \fn User
 \param name
 \param id
 \param isReceptionist
 \param isManagerX
 \param isManagerZ
 \param isAdministrator
 \param parent
*/
	SH_User(QString name = "", int id = 0, bool isReceptionist = false, bool isManagerX = false, bool isManagerZ = false, bool isAdministrator = false, QObject *parent = 0);
	
/*!
	\brief \~french

	\fn name
	\return QString
	*/
	QString name() const;
	
/*!
	\brief \~french

	\fn id
	\return int
	*/
	int id() const { return this->m_id; }
	
/*!
	\brief \~french

	\fn isReceptionist
	\return bool
	*/
	bool isReceptionist() const;
	
/*!
	\brief \~french

	\fn isManagerX
	\return bool
	*/
	bool isManagerX() const { return this->m_managerX; }
	
/*!
	\brief \~french

	\fn isManagerZ
	\return bool
	*/
	bool isManagerZ() const { return this->m_managerZ; }
	
/*!
	\brief \~french

	\fn isAdministrator
	\return bool
	*/
	bool isAdministrator() const { return this->m_administrator; }
	
/*!
	\brief \~french

	\fn roles
	\return int
	*/
	int roles() const;
	
/*!
	\brief \~french

	\fn isValid
	\return bool
	*/
	bool isValid() const;

	
/*!
	\brief \~french

	\fn logIn
	\param login
	\param pass
	\return User
	*/
	static SH_User *logIn(QString login, QString pass);
	
/*!
	\brief \~french

	\fn traineeExists
	\param login
	\return bool
	*/
	static bool traineeExists(QString login);
	
/*!
	\brief \~french

	\fn userExists
	\param login
	\return bool
	*/
	static bool userExists(QString login);

public slots:
	
/*!
	\brief \~french

	\fn exists
	\param login
	\return QVariant
	*/
	static QVariant exists(QVariant login) {return QVariant(SH_User::userExists(login.toString()) || SH_User::traineeExists(login.toString()));}
signals:
	
/*!
	\brief \~french

	\fn nameChanged
	*/
	void nameChanged();
	
/*!
	\brief \~french

	\fn rolesChanged
	*/
	void rolesChanged();
	
/*!
	\brief \~french

	\fn validityChanged
	*/
	void validityChanged();

private:
	
/*!
	\brief \~french

	\fn setName
	\param name
	*/
	void setName(QString name);
	
/*!
	\brief \~french

	\fn setID
	\param id
	*/
	void setID(int id);

	
/*!
	*\brief \~french m_name
	*/
	QString m_name;
	
/*!
	*\brief \~french m_receptionist
	*/
	bool m_receptionist;
	
/*!
	*\brief \~french m_managerX
	*/
	bool m_managerX;
	
/*!
	*\brief \~french m_managerZ
	*/
	bool m_managerZ;
	
/*!
	*\brief \~french m_administrator
	*/
	bool m_administrator;
	
/*!
	*\brief \~french m_id
	*/
	int m_id;
};
/*}*/
#endif /* USER_H*/
