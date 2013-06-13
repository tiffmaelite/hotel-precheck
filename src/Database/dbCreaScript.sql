CONNECT 'localhost:/home/tiff/Stage-IUT/app/QtQMLapp/src/PreCheck/PreCheckDB.fbd' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;

DROP DATABASE;

COMMIT;

CREATE DATABASE 'localhost:/home/tiff/Stage-IUT/app/QtQMLapp/src/PreCheck/PreCheckDB.fbd' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;

CONNECT 'localhost:/home/tiff/Stage-IUT/app/QtQMLapp/src/PreCheck/PreCheckDB.fbd' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;

CREATE DOMAIN BOOLEAN AS CHAR(1) CHECK (value is null or value in ('','0', '1'));

CREATE TABLE ADDRESSES
(
ID INTEGER NOT NULL,
CLIENT_ID INTEGER NOT NULL,
CONTACT VARCHAR(30) NOT NULL,
STREET VARCHAR(50) NOT NULL,
NUMBER VARCHAR(4),
CITY VARCHAR(40) NOT NULL,
ZIPCODE VARCHAR(9),
COUNTRY VARCHAR(30) NOT NULL,
PHONE VARCHAR(13),
CONSTRAINT PK_ADDRESSES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_ADDRESSES_CONTACTADDRESS UNIQUE (CONTACT,STREET,NUMBER,CITY,COUNTRY),
CONSTRAINT CK_VAL_ADDRESSES_PHONE CHECK (PHONE SIMILAR TO '[\+|00][[1-9]]{3}[[:DIGIT:]]{8}')
);

CREATE SEQUENCE SEQ_ADDRESSES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_ADDRESSES_AUTOID for ADDRESSES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_ADDRESSES_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE NATIONALITIES
(
ID INTEGER NOT NULL,
CODE VARCHAR(3) NOT NULL,
LABEL VARCHAR(50) NOT NULL,
CONSTRAINT PK_NATIONALITIES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_NATIONALITIES_CODE UNIQUE (CODE),
CONSTRAINT UQ_NATIONALITIES_LABEL UNIQUE (LABEL)
);

CREATE SEQUENCE SEQ_NATIONALITIES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_NATIONALITIES_AUTOID for NATIONALITIES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_NATIONALITIES_ID,1);
 end
 end!!
 SET TERM ; !!

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

CREATE TABLE BOOKINGS
(
ID INTEGER NOT NULL,
CLIENT_ID INTEGER NOT NULL,
GROUP_ID INTEGER,
ROOMTYPE_ID INTEGER NOT NULL,
NBADULTS INTEGER DEFAULT 0,
NBCHILDREN INTEGER DEFAULT 0,
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
 new.id = gen_id(SEQ_BOOKINGS_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE BILLINGSTYPES
(
ID INTEGER NOT NULL,
LABEL VARCHAR(20),
CONSTRAINT PK_BILLINGSTYPES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_BILLINGSTYPES_LABEL UNIQUE (LABEL)
);

CREATE SEQUENCE SEQ_BILLINGSTYPES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_BILLINGSTYPES_AUTOID for BILLINGSTYPES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_BILLINGSTYPES_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE BILLS
(
ID INTEGER NOT NULL,
BILLING_ID INTEGER NOT NULL,
BILLING_BILLID INTEGER NOT NULL,
BILLTYPE_ID INTEGER NOT NULL,
NOTE VARCHAR(255),
CONSTRAINT PK_BILLS_ID PRIMARY KEY (ID),
CONSTRAINT UQ_BILLS_IDBILLID UNIQUE (BILLING_ID,BILLING_BILLID)
);

CREATE SEQUENCE SEQ_BILLS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_BILLS_AUTOID for BILLS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_BILLS_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE BILLSTYPES
(
ID INTEGER NOT NULL,
LABEL VARCHAR(20),
CONSTRAINT PK_BILLSTYPES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_BILLSTYPES_LABEL UNIQUE (LABEL)
);

CREATE SEQUENCE SEQ_BILLSTYPES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_BILLSTYPES_AUTOID for BILLSTYPES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_BILLSTYPES_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE CHARGEDSERVICES
(
SERVICE_ID INTEGER NOT NULL,
BILL_ID INTEGER NOT NULL,
RECEPTIONIST_ID INTEGER NOT NULL,
INVOICINGDATE DATE NOT NULL,
QUANTITY INT NOT NULL,
CHARGEDUNITYPRICE FLOAT,
ISPRINTED BOOLEAN DEFAULT '0' NOT NULL,
ISPAYED BOOLEAN DEFAULT '0' NOT NULL,
PAIEMENTDATE DATE,
CONSTRAINT PK_CHARGEDSERVICES_SERVICEBILL PRIMARY KEY (SERVICE_ID,BILL_ID)
);

CREATE TABLE CLIENTS
(
ID INTEGER NOT NULL,
NAME VARCHAR(35) NOT NULL,
PHONE VARCHAR(12),
EMAIL VARCHAR(50),
IDCARDSCAN VARCHAR(100),
NATIONALITY_ID INTEGER NOT NULL,
HOMEADDRESS_ID INTEGER,
ISCURRENT BOOLEAN DEFAULT '0' NOT NULL,
CONSTRAINT PK_CLIENTS_ID PRIMARY KEY (ID),
CONSTRAINT UQ_CLIENTS_EMAIL UNIQUE (EMAIL),
CONSTRAINT CK_VAL_CLIENTS_EMAIL CHECK(EMAIL SIMILAR TO '[[[:ALNUM:]\._%\+\-]+@[[:ALNUM:]\.-]+\.[[:ALPHA:]]+]?'),
CONSTRAINT CK_VAL_CLIENTS_PHONE CHECK(PHONE SIMILAR TO '[[\+|00][[1-9]]{3}[[:DIGIT:]]{8}]?')
);

CREATE SEQUENCE SEQ_CLIENTS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_CLIENTS_AUTOID for CLIENTS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_CLIENTS_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE GROUPS
(
ID INTEGER NOT NULL,
NAME VARCHAR(25) NOT NULL,
CONTACT_ID INTEGER,
CONSTRAINT PK_GROUPS_ID PRIMARY KEY (ID),
CONSTRAINT UQ_GROUPS_NAME UNIQUE (NAME)
);

CREATE SEQUENCE SEQ_GROUPS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_GROUPS_AUTOID for GROUPS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_GROUPS_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE ROOMS
(
ID INTEGER NOT NULL,
ROOMTYPE_ID INTEGER NOT NULL,
NUMBER SMALLINT NOT NULL,
FLOOR SMALLINT NOT NULL,
ISCLEANED BOOLEAN DEFAULT '1' NOT NULL,
CONSTRAINT PK_ROOMS_ID PRIMARY KEY (ID),
CONSTRAINT UQ_ROOMS_NUMBER UNIQUE (NUMBER)
);

CREATE SEQUENCE SEQ_ROOMS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_ROOMS_AUTOID for ROOMS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_ROOMS_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE ROOMSTYPES
(
ID INTEGER NOT NULL,
LABEL VARCHAR(20) NOT NULL,
DESCRIPTION VARCHAR(255),
PRICEMIN FLOAT NOT NULL,
PRICEMAX FLOAT,
CONSTRAINT PK_ROOMSTYPES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_ROOMSTYPES_LABEL UNIQUE (LABEL)
);

CREATE SEQUENCE SEQ_ROOMSTYPES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_ROOMSTYPES_AUTOID for ROOMSTYPES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_ROOMSTYPES_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE SERVICES
(
ID INTEGER NOT NULL,
SERVICETYPE_ID INTEGER NOT NULL,
DISPLAYEDNAME VARCHAR(100) NOT NULL,
PRINTEDNAME VARCHAR(100),
PRICE1 FLOAT NOT NULL,
PRICE2 FLOAT,
ISAVAILABLE BOOLEAN DEFAULT '1'  NOT NULL,
CONSTRAINT PK_SERVICES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_SERVICES_DISPLAYEDNAME UNIQUE (DISPLAYEDNAME),
CONSTRAINT UQ_SERVICES_PRINTEDNAME UNIQUE (PRINTEDNAME)
);

CREATE SEQUENCE SEQ_SERVICES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_SERVICES_AUTOID for SERVICES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_SERVICES_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE SERVICESFAMILIES
(
ID INTEGER NOT NULL,
LABEL VARCHAR(25) NOT NULL,
CONSTRAINT PK_SERVICESFAMILIES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_SERVICESFAMILIES_LABEL UNIQUE (LABEL)
);

CREATE SEQUENCE SEQ_SERVICESFAMILIES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_SERVICESFAMILIES_AUTOID for SERVICESFAMILIES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_SERVICESFAMILIES_ID,1);
 end
 end!!
 SET TERM ; !!
 CREATE TABLE SERVICESTYPES
 (
 ID INTEGER NOT NULL,
 LABEL VARCHAR(25) NOT NULL,
 SERVICEFAMILY_ID INTEGER NOT NULL,
 VAT_ID INTEGER NOT NULL,
 ROOMNEEDED BOOLEAN DEFAULT '1' NOT NULL,
 CONSTRAINT PK_SERVICESTYPES_ID PRIMARY KEY (ID),
 CONSTRAINT UQ_SERVICESTYPES_LABEL UNIQUE (LABEL)
 );

CREATE SEQUENCE SEQ_SERVICESTYPES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_SERVICESTYPES_AUTOID for SERVICESTYPES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_SERVICESTYPES_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE VAT
(
ID INTEGER NOT NULL,
LABEL VARCHAR(20) NOT NULL,
PERCENTAGE FLOAT,
STARTDATE DATE,
ENDDATE DATE,
CONSTRAINT PK_VAT_ID PRIMARY KEY (ID)
);

CREATE SEQUENCE SEQ_VAT_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_VAT_AUTOID for VAT
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_VAT_ID,1);
 end
 end!!
 SET TERM ; !!

CREATE TABLE USERS
(
ID INTEGER NOT NULL,
LOGIN VARCHAR(20) NOT NULL,
ENCRYPTEDPASS VARCHAR(255) NOT NULL,
ISRECEPTIONIST BOOLEAN DEFAULT '0' NOT NULL,
ISMANAGERX BOOLEAN DEFAULT '0' NOT NULL,
ISMANAGERZ BOOLEAN DEFAULT '0' NOT NULL,
ISADMINISTRATOR BOOLEAN DEFAULT '0' NOT NULL,
CONSTRAINT PK_USERS_ID PRIMARY KEY (ID),
CONSTRAINT UQ_USERS_LOGIN UNIQUE (LOGIN)
);

CREATE SEQUENCE SEQ_USERS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_USERS_AUTOID for USERS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_USERS_ID,1);
 end
 end!!
 SET TERM ; !!

COMMIT;

ALTER TABLE SERVICESTYPES
ADD CONSTRAINT FK_SERVICESTYPES_VAT	FOREIGN KEY (VAT_ID) REFERENCES VAT (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_SERVICESTYPES_FAMILY	FOREIGN KEY (SERVICEFAMILY_ID) REFERENCES SERVICESFAMILIES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;;

ALTER TABLE SERVICES
ADD CONSTRAINT FK_SERVICES_TYPE	FOREIGN KEY (SERVICETYPE_ID) REFERENCES SERVICESTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE ROOMS
ADD CONSTRAINT FK_ROOMS_TYPE	FOREIGN KEY (ROOMTYPE_ID) REFERENCES ROOMSTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE GROUPS
ADD CONSTRAINT FK_GROUPS_CONTACTCLIENT FOREIGN KEY (CONTACT_ID) REFERENCES CLIENTS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE CLIENTS
ADD CONSTRAINT FK_CLIENTS_ADDRESS FOREIGN KEY (HOMEADDRESS_ID) REFERENCES ADDRESSES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_CLIENTS_NATIONALITY FOREIGN KEY (NATIONALITY_ID) REFERENCES NATIONALITIES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE CHARGEDSERVICES
ADD CONSTRAINT FK_CHARGEDSERVICES_USER FOREIGN KEY (RECEPTIONIST_ID) REFERENCES USERS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_CHARGEDSERVICES_SERVICE FOREIGN KEY (SERVICE_ID) REFERENCES SERVICES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_CHARGEDSERVICES_BILL FOREIGN KEY (BILL_ID) REFERENCES BILLS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE BILLS
ADD CONSTRAINT FK_BILLS_BILLING FOREIGN KEY (BILLING_ID) REFERENCES BILLINGS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLS_TYPE FOREIGN KEY (BILLTYPE_ID) REFERENCES BILLSTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE BILLINGS
ADD CONSTRAINT FK_BILLINGS_ADDRESS FOREIGN KEY (BILLINGADDRESS_ID) REFERENCES ADDRESSES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLINGS_GROUP FOREIGN KEY (GROUP_ID) REFERENCES GROUPS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLINGS_TYPE FOREIGN KEY (BILLINGSTYPE_ID) REFERENCES BILLINGSTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLINGS_CLIENT FOREIGN KEY (CLIENT_ID) REFERENCES CLIENTS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLINGS_ROOM FOREIGN KEY (ROOM_ID) REFERENCES ROOMS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BILLINGS_BOOKING FOREIGN KEY (BOOKING_ID) REFERENCES BOOKINGS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE BOOKINGS
ADD CONSTRAINT FK_BOOKINGS_GROUP FOREIGN KEY (GROUP_ID) REFERENCES GROUPS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BOOKINGS_CLIENT FOREIGN KEY (CLIENT_ID) REFERENCES CLIENTS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,
ADD CONSTRAINT FK_BOOKINGS_ROOMTYPE FOREIGN KEY (ROOMTYPE_ID) REFERENCES ROOMSTYPES (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

ALTER TABLE ADDRESSES
ADD CONSTRAINT FK_ADDRESSES_CLIENT FOREIGN KEY (CLIENT_ID) REFERENCES CLIENTS (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

COMMIT;

CREATE VIEW ROOMSINFOS AS
SELECT
ROOMS.ID, ROOMS.NUMBER, ROOMS.FLOOR,
ROOMSTYPES.LABEL, ROOMSTYPES.DESCRIPTION, ROOMSTYPES.PRICEMIN, ROOMSTYPES.PRICEMAX,
(CASE B.ISAVAILABLE WHEN '1' THEN (CASE ROOMS.ISCLEANED WHEN '1' THEN '1' ELSE '' END) ELSE '0' END) AS AVAILABILITY
FROM ROOMS
LEFT JOIN (SELECT CAST((CASE WHEN COUNT(*)>0 THEN '0' ELSE '1' END) AS BOOLEAN) AS ISAVAILABLE, BILLINGS.ROOM_ID FROM BILLINGS WHERE ISCLOSED='0' GROUP BY ROOM_ID) AS B ON ROOMS.ID=B.ROOM_ID
LEFT JOIN ROOMSTYPES ON ROOMS.ROOMTYPE_ID=ROOMSTYPES.ID
ORDER BY ROOMS.NUMBER;

COMMIT;

CREATE VIEW BILLINGSINFOS AS
SELECT
BILLINGS.ID,
CLIENTS.NAME,
ROOMDESC,
CAST((CASE WHEN BILLINGS.NBADULTS IS NULL THEN 0 WHEN BILLINGS.NBCHILDREN IS NULL THEN 0 ELSE CAST(CAST(BILLINGS.NBADULTS AS INTEGER)+CAST(BILLINGS.NBCHILDREN AS INTEGER) AS INTEGER) END) AS INTEGER) AS NBPEOPLE,
BILLINGS.ARRIVINGDATE, BILLINGS.DEPARTUREDATE, BILLINGS.EXPECTEDDEPARTUREDATE,
BILLINGSTYPES.LABEL
FROM BILLINGS
LEFT JOIN (SELECT ROOMS.ID, (ROOMS.NUMBER || '(' || ROOMSTYPES.LABEL || ')') AS ROOMDESC FROM ROOMS LEFT JOIN ROOMSTYPES ON ROOMS.ROOMTYPE_ID = ROOMSTYPES.ID) AS R ON R.ID = BILLINGS.ROOM_ID
LEFT JOIN CLIENTS ON CLIENTS.ID = BILLINGS.CLIENT_ID
LEFT JOIN BILLINGSTYPES ON BILLINGSTYPES.ID = BILLINGS.BILLINGSTYPE_ID
WHERE BILLINGS.ISCLOSED = '0'
ORDER BY BILLINGS.ARRIVINGDATE;

COMMIT;

create procedure logPeriodicBalance (PERIODNAME CHAR(1) CHARACTER SET UTF8 DEFAULT NULL)
as
declare variable nowtmstamp = CURRENT_TIMESTAMP;
declare variable PERIOD as varchar(11)
begin
case PERIODNAME
when Y THEN PERIOD =  YEAR
when M THEN PERIOD = MONTH
when W THEN PERIOD = WEEK
when D THEN PERIOD = DAY
--when H THEN PERIOD =  HOUR --useless: too precise
end case;
-- SELECT SUM(CHARGEDPRICE) FROM CHARGEDSERVICES WHERE datediff(PERIOD, PAIEMENTDATE, nowtmstamp) < 1 AND datediff(PERIOD, PAIEMENTDATE, nowtmstamp) >= 0 INTO :PERIODICBALANCE; --better create trigger with counter
-- create new counter (raz)
INSERT INTO PERIODICLOG(date, hour, timestamp, balance) VALUES (extract(day from nowtmstamp), extract(hour from nowtmstamp), nowtmstamp, 0);
end
