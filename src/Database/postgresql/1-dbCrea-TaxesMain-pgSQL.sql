CREATE TABLE TAXES
(
  ID SERIAL,
  LABEL VARCHAR(20) NOT NULL,
  PERCENTAGE FLOAT,
  STARTDATE DATE,
  ENDDATE DATE,
  CONSTRAINT PK_TAXES_ID PRIMARY KEY (ID)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_taxes
--BEFORE UPDATE ON taxes
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
