CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;


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

 COMMIT;
