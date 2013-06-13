#ifndef ADAPTDATABASE_H
#define ADAPTDATABASE_H
#include "genericstate.h"

/*!
 \brief
 \class  adaptDatabase TODO comment this adaptdatabase.h "logic/adaptdatabase.h"
*/
class adaptDatabase : public GenericState
{
    Q_OBJECT
public:
/*!
 \brief
 \fn adaptDatabase TODO comment this
 \param name TODO comment this
 \param parent TODO comment this
*/
    adaptDatabase(QString name, QState *parent = 0);

    /*!
     \brief
     \fn insertUpdate TODO comment this
     \param table TODO comment this
     \param content TODO comment this
     \return bool TODO comment this
    */
    bool insertUpdate(QString table, QVariantMap content);

signals:

public slots:

};

#endif // ADAPTDATABASE_H
