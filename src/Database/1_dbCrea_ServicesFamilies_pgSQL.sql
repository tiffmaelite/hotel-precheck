CONNECT TO "PreCheckDB" AS precheck-hotel USER 'precheck' USING 'hotel';

COMMIT;

CREATE TABLE SERVICESFAMILIES
(
ID SERIAL,
LABEL VARCHAR(25) NOT NULL,
CONSTRAINT PK_SERVICESFAMILIES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_SERVICESFAMILIES_LABEL UNIQUE (LABEL)
);


 COMMIT;
