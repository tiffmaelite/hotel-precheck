CREATE TABLE SERVICESFIELDS
(
  ID SERIAL,
  LABEL VARCHAR(25) NOT NULL,
  SQLTYPE VARCHAR(100) DEFAULT 'TEXT' NOT NULL,
  CONSTRAINT PK_SERVICESFIELDS_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_SERVICESFIELDS_LABEL UNIQUE (LABEL)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_SERVICESFIELDS
--BEFORE UPDATE ON SERVICESFIELDS
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
