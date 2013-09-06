CREATE TABLE hourlybalcount
(
  hcreationtime TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  hyearlog SMALLINT,
  hmonthlog SMALLINT,
  hdaylog SMALLINT,
  hhourlog SMALLINT,
  hbalance DECIMAL,
  CONSTRAINT PK_HOURLYBALCOUNT_CREATION PRIMARY KEY (hcreationtime)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_hourlybalcount
--BEFORE UPDATE ON hourlybalcount
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();

