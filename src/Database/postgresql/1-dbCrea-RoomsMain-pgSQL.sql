CREATE TABLE ROOMS
(
  ID SERIAL,
  ROOMTYPE_ID INTEGER NOT NULL,
  NUMBER SMALLINT NOT NULL,
  FLOOR SMALLINT NOT NULL,
  ISCLEANED BOOLEAN DEFAULT '1' NOT NULL,
  CONSTRAINT PK_ROOMS_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_ROOMS_NUMBER UNIQUE (NUMBER)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_ROOMS
--BEFORE UPDATE ON ROOMS
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
