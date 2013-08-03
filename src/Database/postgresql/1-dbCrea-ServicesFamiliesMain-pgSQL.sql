CREATE TABLE SERVICESFAMILIES
(
  ID SERIAL,
  LABEL VARCHAR(25) NOT NULL,
  CONSTRAINT PK_SERVICESFAMILIES_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_SERVICESFAMILIES_LABEL UNIQUE (LABEL)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_SERVICESFAMILIES
--BEFORE UPDATE ON SERVICESFAMILIES
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
