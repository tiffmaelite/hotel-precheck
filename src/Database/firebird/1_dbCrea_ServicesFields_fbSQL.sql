CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;

CREATE TABLE SERVICESFIELDS
 (
 ID INTEGER NOT NULL,
 LABEL VARCHAR(25) NOT NULL,
 SQLTYPE VARCHAR(100) DEFAULT 'TEXT' NOT NULL,
 CONSTRAINT PK_SERVICESFIELDS_ID PRIMARY KEY (ID),
 CONSTRAINT UQ_SERVICESFIELDS_LABEL UNIQUE (LABEL)
 );

CREATE SEQUENCE SEQ_SERVICESFIELDS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_SERVICESFIELDS_AUTOID for SERVICESFIELDS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = NEXT VALUE FOR SEQ_SERVICESFIELDS_ID;
 end
 end!!
 SET TERM ; !!

 COMMIT;
