CREATE TABLE REPORTSTYPES
(
  ID SERIAL,
  LABEL VARCHAR(30),
  DESCRIPTION VARCHAR(255),
  GENERATIONQUERY VARCHAR(1024),
  CONSTRAINT PK_REPORTSTYPES_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_REPORTSTYPES_QUERY UNIQUE (GENERATIONQUERY),
  CONSTRAINT UQ_REPORTSTYPES_LABEL UNIQUE (LABEL)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_REPORTSTYPES
--BEFORE UPDATE ON REPORTSTYPES
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
