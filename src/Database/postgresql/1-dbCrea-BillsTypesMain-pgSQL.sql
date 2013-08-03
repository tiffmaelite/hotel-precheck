CREATE TABLE BILLSTYPES
(
  ID SERIAL,
  LABEL VARCHAR(20),
  CONSTRAINT PK_BILLSTYPES_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_BILLSTYPES_LABEL UNIQUE (LABEL)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_BILLSTYPES
--BEFORE UPDATE ON BILLSTYPES
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
