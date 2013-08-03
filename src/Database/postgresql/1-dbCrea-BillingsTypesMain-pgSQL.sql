CREATE TABLE BILLINGSTYPES
(
  ID SERIAL,
  LABEL VARCHAR(20),
  NBBILLS INT NOT NULL,
  CONSTRAINT PK_BILLINGSTYPES_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_BILLINGSTYPES_LABEL UNIQUE (LABEL)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_BILLINGSTYPES
--BEFORE UPDATE ON BILLINGSTYPES
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
