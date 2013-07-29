CREATE TABLE balancelog
(
  yearlog INT,
  monthlog INT,
  daylog INT,
  hourlog INT,
  balance FLOAT,
  CONSTRAINT PK_BALANCELOG_DATE PRIMARY KEY (yearlog, monthlog, daylog, hourlog)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_balancelog
--BEFORE UPDATE ON balancelog
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
