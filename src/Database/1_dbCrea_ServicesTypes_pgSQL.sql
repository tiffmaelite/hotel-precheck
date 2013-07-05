CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


 CREATE TABLE SERVICESTYPES
 (
 ID SERIAL,
 LABEL VARCHAR(25) NOT NULL,
 SERVICEFAMILY_ID INTEGER NOT NULL,
 VAT_ID INTEGER NOT NULL,
 ROOMNEEDED BOOLEAN DEFAULT '1' NOT NULL,
 CONSTRAINT PK_SERVICESTYPES_ID PRIMARY KEY (ID),
 CONSTRAINT UQ_SERVICESTYPES_LABEL UNIQUE (LABEL)
 );

 COMMIT;
