CREATE TABLE monthlybalcount
(
  mcreationtime TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  myearlog INT,
  mmonthlog INT,
  mbalance FLOAT,
  CONSTRAINT PK_MONTHLYBALCOUNT_CREATION PRIMARY KEY (mcreationtime)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_monthlybalcount
--BEFORE UPDATE ON monthlybalcount
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
