CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


CREATE TABLE GROUPS
(
ID SERIAL,
NAME VARCHAR(25) NOT NULL,
CONTACT_ID INTEGER,
CONSTRAINT PK_GROUPS_ID PRIMARY KEY (ID),
CONSTRAINT UQ_GROUPS_NAME UNIQUE (NAME)
);

 COMMIT;
