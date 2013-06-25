#ifndef FILESELECTIONSTATE_H
#define FILESELECTIONSTATE_H
#include "SH_IOState.h"
/*namespace SimplHotel
{*/
/*!
 * \brief \~french The SH_FileSelectionState class
 */
class SH_FileSelectionState : public SH_InOutState
{
	Q_OBJECT
public:
/*!
 * \brief \~french
 * \fn FileSelectionState
 * \param output
 * \param name
 * \param parent
*/
	SH_FileSelectionState(QString output, QString name, QState *parent = 0);
signals:
public slots:
};
/*}*/
#endif /* FILESELECTIONSTATE_H*/
