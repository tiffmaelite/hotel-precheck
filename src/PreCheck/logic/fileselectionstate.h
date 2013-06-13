#ifndef FILESELECTIONSTATE_H
#define FILESELECTIONSTATE_H
#include "iostate.h"
class FileSelectionState : public IOState
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
    FileSelectionState(QString output, QString name, QState *parent = 0);

signals:

public slots:

};

#endif // FILESELECTIONSTATE_H
