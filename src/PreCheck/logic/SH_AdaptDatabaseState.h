#ifndef ADAPTDATABASE_H
#define ADAPTDATABASE_H
#include "SH_GenericDebugableState.h"

/*!
\brief \~french La classe SH_AdaptDatabase fournit un état générique qui enregistre des variables la base de données. Chaque machine SH_InOutStateMachine passe par un tel état juste avant son état final.
 \class SH_AdaptDatabase
\headerfile SH_AdaptDatabase.h "logic/SH_AdaptDatabase.h"
*/
class SH_AdaptDatabaseState : public SH_GenericState
{
    Q_OBJECT
public:
/*!
\brief \~french Construit une instance de la classe SH_AdaptDatabaseState
 \fn adaptDatabase
 \param name Le nom de l'état
 \param parent L'état parent
*/
    SH_AdaptDatabaseState(QString name, QState *parent = 0);

    /*!
    \brief \~french Enregistre dans la base de données les valeurs données
     \fn insertUpdate
     \param table Le nom de la table à modifier
     \param content Le contenu à enregistrer, sous la forme d'une \a QVariantMap associant les champs de la table aux valeurs à insérer/modifier
     \return bool Retourne \a true si l'enregistrement a réussi, \a false sinon
    */
    QVariant insertUpdate(QString table, QVariantMap content);

signals:

public slots:

};

#endif /* ADAPTDATABASE_H*/
