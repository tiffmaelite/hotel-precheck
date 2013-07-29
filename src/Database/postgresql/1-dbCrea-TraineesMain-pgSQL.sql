CREATE TABLE TRAINEES
(
  ID SERIAL,
  LOGIN VARCHAR(20) NOT NULL,
  ENCRYPTEDPASS VARCHAR(255) NOT NULL,
  ISACTIVATED BOOLEAN DEFAULT '1' NOT NULL,
  CONSTRAINT PK_TRAINEES_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_TRAINEES_LOGIN UNIQUE (LOGIN)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_trainees
--BEFORE UPDATE ON TRAINEES
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
