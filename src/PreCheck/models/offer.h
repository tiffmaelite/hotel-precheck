#ifndef OFFER_H
#define OFFER_H

class Offer : public QSqlRelationalTableModel
{
    Q_OBJECT
public:
    Offer(QObject *parent = 0);
	
	 Q_PROPERTY(QString id READ ID);
	 Q_PROPERTY(QString name READ name WRITE setName RESET unsetName);
	 Q_PROPERTY(QString name READ name WRITE setName RESET unsetName);
    
};

#endif // OFFER_H
