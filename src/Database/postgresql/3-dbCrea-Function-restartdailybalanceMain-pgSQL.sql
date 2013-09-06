CREATE OR REPLACE FUNCTION  restartdailybalance (restartyear SMALLINT, restartmonth SMALLINT, restartday SMALLINT)
RETURNS BOOLEAN
AS $$
  DECLARE previousyear SMALLINT;
  DECLARE previousmonth SMALLINT;
  DECLARE nowtimestamp TIMESTAMP;
  DECLARE oldbalance DECIMAL;
  DECLARE currentbalance DECIMAL;
  DECLARE restarthour SMALLINT;
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
  SELECT dbalance INTO oldbalance FROM dailybalcount WHERE dyearlog = previousyear AND dmonthlog = previousmonth AND ddaylog = (restartday-1) AND hourlog = 0;
  IF oldbalance IS NULL THEN
	oldbalance = 0.0;
  END IF;
  SELECT balance INTO currentbalance FROM balancelog_archive WHERE yearlog = previousyear AND monthlog = previousmonth AND daylog = (restartday-1) AND hourlog = 0;
  IF currentbalance IS NULL THEN
	currentbalance=0.0;
  END IF;
  SELECT gen_upsert_BALANCELOG (hstore(ARRAY[['balance','('||oldbalance||' + '||currentbalance||')'],['yearlog',previousyear],['monthlog',previousmonth],['daylog',restartday-1],['hourlog','0']]));
  -- CREATE new counter (ràz)
  INSERT INTO dailybalcount(dcreationtime, dyearlog, dmonthlog, ddaylog, dbalance) VALUES (nowtimestamp, restartyear, restartmonth, restartday, 0);
  --propagate restart
  SELECT hhourlog INTO restarthour FROM hourlybalcount WHERE hcreationtime >= (SELECT MAX(hcreationtime) FROM hourlybalcount);
  SELECT restarthourlybalance(restartyear, restartmonth, restartday, restarthour);
  RETURN TRUE;
EXCEPTION
  WHEN QUERY_CANCELED OR OTHERS THEN
	RETURN FALSE;
END;
$$ LANGUAGE plpgsql;
