#ifndef FILESELECTIONSTATE_H
#define FILESELECTIONSTATE_H
#include "SH_IOState.h"

class SH_FileSelectionState : public SH_InOutState
{
    Q_OBJECT
public:
/*!
 \brief
 \fn FileSelectionState TODO comment this
 \param output TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
    SH_FileSelectionState(QString output, QString name, QState *parent = 0);

signals:

public slots:

};

#endif // FILESELECTIONSTATE_H
