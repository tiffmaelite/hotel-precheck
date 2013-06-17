CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;

CREATE TABLE TAXES
(
ID INTEGER NOT NULL,
LABEL VARCHAR(20) NOT NULL,
PERCENTAGE FLOAT,
STARTDATE DATE,
ENDDATE DATE,
CONSTRAINT PK_TAXES_ID PRIMARY KEY (ID)
);

CREATE SEQUENCE SEQ_TAXES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_TAXES_AUTOID for TAXES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_TAXES_ID,1);
 end
 end!!
 SET TERM ; !!

 COMMIT;
