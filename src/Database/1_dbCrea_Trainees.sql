CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' TRAINEE 'SYSDBA' PASSWORD 'masterkey';

COMMIT;


CREATE TABLE TRAINEES
(
ID INTEGER NOT NULL,
LOGIN VARCHAR(20) NOT NULL,
ENCRYPTEDPASS VARCHAR(255) NOT NULL,
CONSTRAINT PK_TRAINEES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_TRAINEES_LOGIN UNIQUE (LOGIN)
);

CREATE SEQUENCE SEQ_TRAINEES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_TRAINEES_AUTOID for TRAINEES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_TRAINEES_ID,1);
 end
 end!!
 SET TERM ; !!

 COMMIT;
