CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


CREATE TABLE BOOKINGS
(
ID INTEGER NOT NULL,
CLIENT_ID INTEGER NOT NULL,
ROOMTYPE_ID INTEGER NOT NULL,
NBADULTS SMALLINT DEFAULT 0,
NBCHILDREN SMALLINT DEFAULT 0,
EXPECTEDARRIVINGDATE DATE NOT NULL,
EXPECTEDDEPARTUREDATE DATE NOT NULL,
BOOKINGDATE DATE NOT NULL,
CONFIRMATIONDATE DATE,
CANCELATIONDATE DATE,
NOTE VARCHAR(255),
CONSTRAINT PK_BOOKINGS_ID PRIMARY KEY (ID),
CONSTRAINT UQ_BOOKINGS_CLIENTARRIVING UNIQUE (CLIENT_ID,EXPECTEDARRIVINGDATE),
CONSTRAINT UQ_BOOKINGS_CLIENTDEPARTURE UNIQUE (CLIENT_ID,EXPECTEDDEPARTUREDATE),
CONSTRAINT CK_POS_BOOKINGS_NBADULTS CHECK (NBADULTS >= 0),
CONSTRAINT CK_POS_BOOKINGS_NBCHILDREN CHECK (NBCHILDREN >= 0)
);

CREATE SEQUENCE SEQ_BOOKINGS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_BOOKINGS_AUTOID for BOOKINGS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = NEXT VALUE FOR SEQ_BOOKINGS_ID;
 end
 end!!
 SET TERM ; !!

 COMMIT;
