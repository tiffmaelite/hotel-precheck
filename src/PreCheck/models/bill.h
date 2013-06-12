#ifndef BILLS_H
#define BILLS_H

class Bills : public QSqlRelationalTableModel
{
    Q_OBJECT
		
public:
    Bills(QString filter = "", QObject *parent = 0);	
};

#endif // BILLS_H
