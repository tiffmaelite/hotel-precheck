CREATE OR REPLACE FUNCTION  restartdailybalance (restartyear INT, restartmonth INT, restartday INT)
RETURNS VOID
AS $$
  DECLARE previousyear INT;
  DECLARE previousmonth INT;
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
  SELECT dbalance FROM daybalancecounter WHERE dyearlog = previousyear AND dmonthlog = previousmonth AND ddaylog = (restartday-1) INTO oldbalance;
  IF oldbalance IS NULL THEN
	oldbalance = 0.0;
  END IF;
  SELECT balance FROM balancelog_archive WHERE yearlog = previousyear AND monthlog = previousmonth AND daylog = (restartday-1) INTO currentbalance;
  IF currentbalance IS NOT NULL THEN
	UPDATE balancelog_archive SET balance = (oldbalance + currentbalance) WHERE yearlog = previousyear AND monthlog = previousmonth AND daylog = (restartday-1);
  ELSE
	INSERT INTO balancelog_archive(yearlog, monthlog, daylog, hourlog, balance) VALUES (previousyear, previousmonth, (restartday-1), 0,	 oldbalance);
  END IF;
  -- CREATE new counter (ràz)
  INSERT INTO dailybalancecounter(dcreationtime, dyearlog, dmonthlog, ddaylog, dbalance) VALUES (nowtimestamp, restartyear, restartmonth, restartday, 0);
END;
$$ LANGUAGE plpgsql;
