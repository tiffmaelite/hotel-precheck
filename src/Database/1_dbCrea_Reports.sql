CONNECT precheck-hotel USER 'precheck' PASSWORD 'hotel';

COMMIT;


CREATE TABLE REPORTSTYPES
(
ID INTEGER NOT NULL,
LABEL VARCHAR(100),
GENERATIONQUERY VARCHAR(1024)
);

CREATE SEQUENCE SEQ_REPORTSTYPES_ID;

 SET TERM !! ;
 CREATE TRIGGER TR_REPORTSTYPES_AUTOID for REPORTSTYPES
 active before insert position 0
 as
 begin
 if ((new.ID is null) or (new.ID = 0)) then
 begin
 new.id = gen_id(SEQ_REPORTSTYPES_ID,1);
 end
 end!!
 SET TERM ; !!

 COMMIT;
