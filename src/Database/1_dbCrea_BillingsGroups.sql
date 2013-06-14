CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;


CREATE TABLE BILLINGSGROUPS
(
ID INTEGER NOT NULL,
GROUP_ID INTEGER NOT NULL,
BILLING_ID INTEGER,
CONSTRAINT PK_BILLINGSGROUPS_ID PRIMARY KEY (ID)
);

CREATE SEQUENCE SEQ_BILLINGSGROUPS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_BILLINGSGROUPS_AUTOID for BILLINGSGROUPS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_BILLINGSGROUPS_ID,1);
 end
 end!!
 SET TERM ; !!

 COMMIT;
