CREATE TABLE TAXES
(
  ID SERIAL,
  LABEL VARCHAR(20) NOT NULL,
  PERCENTAGE FLOAT,
  STARTDATE DATE DEFAULT NULL,
  ENDDATE DATE DEFAULT NULL,
  CONSTRAINT PK_TAXES_ID PRIMARY KEY (ID),
  CONSTRAINT CK_POS_TAXES_PERCENTAGE CHECK (PERCENTAGE >= 0),
  CONSTRAINT CK_ORD_TAXES_DATES CHECK (STARTDATE IS NULL OR ENDDATE IS NULL OR ENDDATE >= STARTDATE)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_taxes
--BEFORE UPDATE ON taxes
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
