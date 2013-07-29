CREATE TABLE GROUPS
(
  ID SERIAL,
  NAME VARCHAR(25) NOT NULL,
  CONTACT_ID INTEGER,
  CONSTRAINT PK_GROUPS_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_GROUPS_NAME UNIQUE (NAME)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_GROUPS
--BEFORE UPDATE ON GROUPS
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
