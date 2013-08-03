CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


CREATE TABLE BILLINGSCLIENTS
(
ID INTEGER NOT NULL,
CLIENT_ID INTEGER NOT NULL,
BILLING_ID INTEGER,
CONSTRAINT PK_BILLINGSCLIENTS_ID PRIMARY KEY (ID)
);

CREATE SEQUENCE SEQ_BILLINGSCLIENTS_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_BILLINGSCLIENTS_AUTOID for BILLINGSCLIENTS
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = NEXT VALUE FOR SEQ_BILLINGSCLIENTS_ID;
 end
 end!!
 SET TERM ; !!

 COMMIT;