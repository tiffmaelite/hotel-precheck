CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;

CREATE TABLE BILLSTYPES
(
ID SERIAL,
LABEL VARCHAR(20),
CONSTRAINT PK_BILLSTYPES_ID PRIMARY KEY (ID),
CONSTRAINT UQ_BILLSTYPES_LABEL UNIQUE (LABEL)
);


 COMMIT;
