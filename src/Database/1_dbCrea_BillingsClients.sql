CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;


CREATE TABLE BILLINGSCLIENTS
(
ID INTEGER NOT NULL,
CLIENT_ID INTEGER NOT NULL,
BILLING_ID INTEGER,
CONSTRAINT PK_BILLINGSCLIENTS_ID PRIMARY KEY (ID)
);

CREATE SEQUENCE SEQ_BILLINGSCLIENTS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_BILLINGSCLIENTS_AUTOID for BILLINGSCLIENTS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_BILLINGSCLIENTS_ID,1);
 end
 end!!
 SET TERM ; !!

 COMMIT;
