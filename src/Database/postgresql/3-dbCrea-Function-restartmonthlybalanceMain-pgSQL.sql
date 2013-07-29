CREATE OR REPLACE FUNCTION  restartmonthlybalance (restartyear INTEGER, restartmonth INTEGER)
RETURNS VOID
AS $$
  DECLARE previousyear INTEGER;
  DECLARE nowtimestamp TIMESTAMP;
  DECLARE oldbalance DECIMAL;
  DECLARE currentbalance DECIMAL;
BEGIN
  nowtimestamp = CURRENT_TIMESTAMP;
  oldbalance = 0.0;
  currentbalance = 0.0;
  IF restartmonth = 1 THEN
	previousyear = restartyear-1;
  ELSE
	previousyear = restartyear;
  END IF;
  SELECT mbalance FROM monthlybalancecounter WHERE myearlog = previousyear AND mmonthlog = (restartmonth-1) INTO oldbalance;
  IF oldbalance IS NULL THEN
	oldbalance = 0.0;
  END IF;
  SELECT balance FROM balancelog_archive WHERE yearlog = previousyear AND monthlog = (restartmonth-1) INTO currentbalance;
  IF currentbalance IS NOT NULL THEN
	UPDATE balancelog_archive SET balance = (oldbalance + currentbalance) WHERE yearlog = previousyear AND monthlog = (restartmonth-1);
  ELSE
	INSERT INTO balancelog_archive(yearlog, monthlog, daylog, hourlog, balance) VALUES (previousyear, (restartmonth-1), 0, 0, oldbalance);
  END IF;
  -- CREATE new counter (ràz)
  INSERT INTO monthlybalancecounter(mcreationtime, myearlog, mmonthlog, mbalance) VALUES (nowtimestamp, restartyear, restartmonth, 0.0);
END;
$$ LANGUAGE plpgsql;
