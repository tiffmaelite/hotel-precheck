#ifndef ADAPTDATABASE_H
#define ADAPTDATABASE_H
#include "SH_GenericDebugableState.h"

/*!
 \brief
 \class SH_ adaptDatabase TODO comment this adaptdatabase.h "logic/adaptdatabase.h"
*/
class SH_AdaptDatabaseState : public SH_GenericState
{
    Q_OBJECT
public:
/*!
 \brief
 \fn SH_adaptDatabase TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
    SH_AdaptDatabaseState(QString name, QState *parent = 0);

    /*!
     \brief
     \fn SH_insertUpdate TODO comment this
     \param table TODO comment this
     \param content TODO comment this
     \return bool TODO comment this
    */
    QVariant insertUpdate(QString table, QVariantMap content);

signals:

public slots:

};

#endif /* ADAPTDATABASE_H*/
