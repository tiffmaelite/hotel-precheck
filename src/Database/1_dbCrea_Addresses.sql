CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;


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
 
 COMMIT;
