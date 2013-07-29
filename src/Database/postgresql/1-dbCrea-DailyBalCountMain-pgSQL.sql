CREATE TABLE dailybalcount
(
  dcreationtime TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  dyearlog INT,
  dmonthlog INT,
  ddaylog INT,
  dbalance FLOAT,
  CONSTRAINT PK_DAYLYBALCOUNT_CREATION PRIMARY KEY (dcreationtime)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_dailybalcount
--BEFORE UPDATE ON dailybalcount
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
