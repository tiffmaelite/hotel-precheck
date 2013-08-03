#ifndef SH_TRAINEESTABLEMODEL_H
#define SH_TRAINEESTABLEMODEL_H

#include "SH_ExtendedProxyTableModel.h"

/*namespace SimplHotel
                {*/
/*!
                \brief \~french

                 \class SH_TraineesTableModel
                \headerfile SH_TraineesTableModel.h "models/SH_TraineesTableModel.h"
                */
class SH_TraineesTableModel : public SH_ExtendedProxyTableModel
{
    Q_OBJECT
public:


    /*!
                \brief \~french

                 \fn SH_TraineesTableModel
                 \param parent
                */
    SH_TraineesTableModel(QObject *parent = 0);


protected:



    /*!
                    \brief \~french

                    \fn fillModel
                    */
    void fillModel();
};
/*}*/

#endif // SH_TRAINEESTABLEMODEL_H
