CREATE TABLE SERVICESDETAILS
(
  SERVICE_ID INTEGER NOT NULL,
  SERVICEFIELD_ID INTEGER NOT NULL,
  FIELDVALUE VARCHAR(255),
  CONSTRAINT PK_SERVICESDETAILS_ID PRIMARY KEY (SERVICE_ID, SERVICEFIELD_ID)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_SERVICESDETAILS
--BEFORE UPDATE ON SERVICESDETAILS
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
