CREATE TABLE ROOMSTYPES
(
  ID SERIAL,
  LABEL VARCHAR(20) NOT NULL,
  DESCRIPTION VARCHAR(255),
  PRICEMIN FLOAT NOT NULL,
  PRICEMAX FLOAT,
  CONSTRAINT PK_ROOMSTYPES_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_ROOMSTYPES_LABEL UNIQUE (LABEL),
  CONSTRAINT CK_ORD_ROOMSTYPES_PRICES CHECK (PRICEMAX IS NULL OR PRICEMAX >= PRICEMIN)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);
--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_roomstypes
--BEFORE UPDATE ON roomstypes
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
