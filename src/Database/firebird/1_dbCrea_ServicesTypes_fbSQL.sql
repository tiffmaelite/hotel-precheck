CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


 CREATE TABLE SERVICESTYPES
 (
 ID INTEGER NOT NULL,
 LABEL VARCHAR(25) NOT NULL,
 SERVICEFAMILY_ID INTEGER NOT NULL,
 VAT_ID INTEGER NOT NULL,
 ROOMNEEDED BOOLEAN DEFAULT '1' NOT NULL,
 CONSTRAINT PK_SERVICESTYPES_ID PRIMARY KEY (ID),
 CONSTRAINT UQ_SERVICESTYPES_LABEL UNIQUE (LABEL)
 );

CREATE SEQUENCE SEQ_SERVICESTYPES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_SERVICESTYPES_AUTOID for SERVICESTYPES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = NEXT VALUE FOR SEQ_SERVICESTYPES_ID;
 end
 end!!
 SET TERM ; !!

 COMMIT;
