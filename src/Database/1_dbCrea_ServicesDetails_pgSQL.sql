CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;

CREATE TABLE SERVICESDETAILS
 (
 SERVICE_ID INTEGER NOT NULL,
 SERVICEFIELD_ID INTEGER NOT NULL,
 FIELDVALUE VARCHAR(255),
 CONSTRAINT PK_SERVICESDETAILS_ID PRIMARY KEY (SERVICE_ID, SERVICEFIELD_ID)
 );

 COMMIT;
