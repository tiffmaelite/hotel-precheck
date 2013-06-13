#include "clientcreation.h"
#include "databasecontentquestionstate.h"
#include "stringquestionstate.h"

ClientCreationStateMachine::ClientCreationStateMachine(QString name, QObject *parent) :
    IOStateMachine("CLIENTS",name, parent)
{
//TODO: adresse, nationalité, carte d'identité
    //StringQuestionState* address = new StringQuestionState("Veuillez entrer l'adresse de résidence"); //ADDRESSCREATIONSTATEMACHINE

}
