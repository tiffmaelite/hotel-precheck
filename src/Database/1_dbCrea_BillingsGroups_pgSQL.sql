CONNECT TO "PreCheckDB" AS precheck-hotel USER 'precheck' USING 'hotel';

COMMIT;


CREATE TABLE BILLINGSGROUPS
(
ID SERIAL,
GROUP_ID INTEGER NOT NULL,
BILLING_ID INTEGER,
CONSTRAINT PK_BILLINGSGROUPS_ID PRIMARY KEY (ID)
);

 COMMIT;
