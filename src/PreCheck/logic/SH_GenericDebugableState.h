#ifndef GENERICSTATE_H
#define GENERICSTATE_H
#include <QState>
#include "SH_NamedObject.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french
 * \class SH_GenericState
 * \headerfile genericstate.h "logic/genericstate.h"
*/
class SH_GenericState : public QState,SH_NamedObject
{
	Q_OBJECT
public:
	
/*!
	* \brief \~french
	* \fn GenericState
	* \param name
	* \param parent
	*/
	SH_GenericState(QString name="", QState *parent = 0);
	
/*!
	* \brief \~french
	* \fn toString
	* \return QString
	*/
	QString toString();
	
/*!
	* \brief \~french
	* \fn isRunning
	* \return bool
	*/
	bool isRunning();
private slots:
	
/*!
	* \brief
	* \fn goNext
	*/
	void emitGoNext();
signals:
	
/*!
	* \brief \~french
	* \fn next
	*/
	void next();
	
/*!
	* \brief \~french
	* \fn goNext
	*/
	void goNext();
protected:
	
/*!
	* \brief \~french
	* \fn onEntry
	* \param event
	*/
	void onEntry(QEvent *event);
	
/*!
	* \brief \~french
	* \fn onExit
	* \param event
	*/
	void onExit(QEvent *event);
private slots:
	
/*!
	* \brief \~french
	* \fn onTransitionTriggered
	*/
	void onTransitionTriggered();
private:
	
/*!
	* \brief \~french
	* \var m_isRunning
	*/
	bool m_isRunning;
};
/*}*/
#endif /* GENERICSTATE_H*/
