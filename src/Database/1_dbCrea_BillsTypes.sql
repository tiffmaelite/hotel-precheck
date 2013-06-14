CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;

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

 COMMIT;
