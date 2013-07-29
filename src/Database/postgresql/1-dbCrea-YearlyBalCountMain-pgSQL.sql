CREATE TABLE yearlybalcount
(
  ycreationtime TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  yyearlog INT,
  ybalance FLOAT,
  CONSTRAINT PK_YEARLYBALCOUNT_CREATION PRIMARY KEY (ycreationtime)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_yearlybalcount
--BEFORE UPDATE ON yearlybalcount
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
