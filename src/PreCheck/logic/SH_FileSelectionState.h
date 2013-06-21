#ifndef FILESELECTIONSTATE_H
#define FILESELECTIONSTATE_H
#include "SH_IOState.h"
/*!
 *\brief \~french  The SH_FileSelectionState class
 */
class SH_FileSelectionState : public SH_InOutState
{
    Q_OBJECT
public:
/*!
\brief \~french 
 \fn SH_FileSelectionState TODO comment this
 \param output TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
    SH_FileSelectionState(QString output, QString name, QState *parent = 0);

signals:

public slots:

};

#endif /* FILESELECTIONSTATE_H*/
