CREATE OR REPLACE FUNCTION  restarthourlybalance (restartyear INTEGER, restartmonth INTEGER, restartday INTEGER, restarthour INTEGER)
RETURNS VOID
AS $$
  DECLARE previousyear INTEGER;
  DECLARE previousmonth INTEGER;
  DECLARE previousday INTEGER;
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
  IF restartday = 1 THEN
	previousmonth = restartmonth-1;
  ELSE
	previousmonth = restartmonth;
  END IF;
  IF restarthour = 1 THEN
	previousday = previousday-1;
  ELSE
	previousday = previousday;
  END IF;
  SELECT hbalance FROM hourlybalancecounter WHERE hyearlog = previousyear AND hmonthlog = previousmonth AND hdaylog = (restartday-1) INTO oldbalance;
  IF oldbalance IS NULL THEN
	oldbalance = 0.0;
  END IF;
  SELECT balance FROM balancelog_archive WHERE yearlog = previousyear AND monthlog = previousmonth AND daylog = previousday AND hourlog = (restarthour-1) INTO currentbalance;
  IF currentbalance IS NOT NULL THEN
	UPDATE balancelog_archive SET balance = (oldbalance + currentbalance) WHERE yearlog = previousyear AND monthlog = previousmonth AND daylog = previousday AND hourlog = (restarthour-1);
  ELSE
	INSERT INTO balancelog_archive(yearlog, monthlog, daylog, hourlog, balance) VALUES (previousyear, previousmonth, previousday, (restarthour-1), oldbalance);
  END IF;
  -- CREATE new counter (ràz)
  INSERT INTO hourlybalancecounter(hcreationtime, hyearlog, hmonthlog, hdaylog, hhourlog, hbalance) VALUES (nowtimestamp, restartyear, restartmonth, restartday, restarthour, 0.0);
END;
$$ LANGUAGE plpgsql;
