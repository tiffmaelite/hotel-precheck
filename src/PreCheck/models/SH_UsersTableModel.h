#ifndef SH_USERSTABLEMODEL_H
#define SH_USERSTABLEMODEL_H


#include "SH_ExtendedSqlProxyModel.h"

/*namespace SimplHotel
        {*/
/*!
        \brief \~french

         \class SH_UsersTableModel
        \headerfile SH_UsersTableModel.h "models/SH_UsersTableModel.h"
        */
class SH_UsersTableModel : public SH_ExtendedProxyModel
{
    Q_OBJECT
public:


    /*!
        \brief \~french

         \fn SH_UsersTableModel
         \param parent
        */
    SH_UsersTableModel(QObject *parent = 0);


protected:



    /*!
            \brief \~french

            \fn fillModel
            */
    void fillModel();
};
/*}*/

#endif // SH_USERSTABLEMODEL_H
