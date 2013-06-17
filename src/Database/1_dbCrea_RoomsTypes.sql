CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;

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

 COMMIT;
