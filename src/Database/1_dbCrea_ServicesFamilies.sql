CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;

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

 COMMIT;