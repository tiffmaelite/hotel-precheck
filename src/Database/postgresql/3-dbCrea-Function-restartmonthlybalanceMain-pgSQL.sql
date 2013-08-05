CREATE OR REPLACE FUNCTION  restartmonthlybalance (restartyear INTEGER, restartmonth INTEGER)
RETURNS BOOLEAN
AS $$
  DECLARE previousyear INTEGER;
  DECLARE nowtimestamp TIMESTAMP;
  DECLARE oldbalance DECIMAL;
  DECLARE currentbalance DECIMAL;
  DECLARE restartday INTEGER;
BEGIN
  nowtimestamp = CURRENT_TIMESTAMP;
  oldbalance = 0.0;
  currentbalance = 0.0;
  IF restartmonth = 1 THEN
	previousyear = restartyear-1;
  ELSE
	previousyear = restartyear;
  END IF;
  SELECT mbalance INTO oldbalance FROM monthlybalcount WHERE myearlog = previousyear AND mmonthlog = (restartmonth-1) AND daylog = 0 AND hourlog = 0;
  IF oldbalance IS NULL THEN
	oldbalance = 0.0;
  END IF;
  SELECT balance INTO currentbalance FROM balancelog_archive WHERE yearlog = previousyear AND monthlog = (restartmonth-1) AND daylog = 0 AND hourlog = 0;
  IF currentbalance IS NULL THEN
	currentbalance=0.0;
  END IF;
  SELECT gen_upsert_BALANCELOG (hstore(ARRAY[['balance','('||oldbalance||' + '||currentbalance||')'],['yearlog',previousyear],['monthlog',restartmonth-1],['daylog','0'],['hourlog','0']]));
  -- CREATE new counter (ràz)
  INSERT INTO monthlybalcount(mcreationtime, myearlog, mmonthlog, mbalance) VALUES (nowtimestamp, restartyear, restartmonth, 0.0);
  --propagate restart
  SELECT ddaylog INTO restartday FROM dailybalcount WHERE dcreationtime >= (SELECT MAX(dcreationtime) FROM dailybalcount);
  SELECT restartdailybalance(restartyear, restartmonth, restartday);
  RETURN TRUE;
EXCEPTION
  WHEN QUERY_CANCELED OR OTHERS THEN
	RETURN FALSE;
END;
$$ LANGUAGE plpgsql;
