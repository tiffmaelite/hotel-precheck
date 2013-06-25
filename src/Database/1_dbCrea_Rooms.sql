CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;

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
 new.id = NEXT VALUE FOR SEQ_ROOMS_ID;
 end
 end!!
 SET TERM ; !!

 COMMIT;
