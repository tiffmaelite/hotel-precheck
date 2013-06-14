CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;


CREATE TABLE BILLINGS
(
ID INTEGER NOT NULL,
CLIENT_ID INTEGER NOT NULL,
GROUP_ID INTEGER,
ROOM_ID INTEGER NOT NULL,
BILLINGSTYPE_ID INTEGER,
BOOKING_ID INTEGER,
BILLINGADDRESS_ID INTEGER NOT NULL,
NBADULTS INTEGER DEFAULT 0,
NBCHILDREN INTEGER DEFAULT 0,
ARRIVINGDATE DATE NOT NULL,
DEPARTUREDATE DATE NOT NULL,
EXPECTEDDEPARTUREDATE DATE,
ISCLOSED BOOLEAN DEFAULT '0' NOT NULL,
NOTE VARCHAR(255),
CONSTRAINT PK_BILLINGS_ID PRIMARY KEY (ID),
CONSTRAINT UQ_BILLINGS_CLIENTARRIVING UNIQUE (CLIENT_ID,ARRIVINGDATE),
CONSTRAINT UQ_BILLINGS_CLIENTDEPARTURE UNIQUE (CLIENT_ID,EXPECTEDDEPARTUREDATE),
CONSTRAINT CK_POS_BILLINGS_NBADULTS CHECK (NBADULTS >= 0),
CONSTRAINT CK_POS_BILLINGS_NBCHILDREN CHECK (NBCHILDREN >= 0)
);

CREATE SEQUENCE SEQ_BILLINGS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_BILLINGS_AUTOID for BILLINGS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_BILLINGS_ID,1);
 end
 end!!
 SET TERM ; !!

 COMMIT;
