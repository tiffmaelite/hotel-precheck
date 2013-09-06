CREATE OR REPLACE FUNCTION  restartyearlybalance ( restartyear SMALLINT )
RETURNS BOOLEAN
AS $$
  DECLARE nowtimestamp TIMESTAMP;
  DECLARE oldbalance DECIMAL;
  DECLARE currentbalance DECIMAL;
  DECLARE restartmonth SMALLINT;
BEGIN
  nowtimestamp = CURRENT_TIMESTAMP;
  oldbalance = 0.0;
  currentbalance = 0.0;
  SELECT ybalance INTO oldbalance FROM yearlybalcount WHERE yyearlog = (restartyear-1);
  IF oldbalance IS NULL THEN
	oldbalance = 0.0;
  END IF;
  SELECT balance INTO currentbalance FROM balancelog_archive WHERE yearlog = (restartyear-1) AND monthlog = 0 AND daylog = 0 AND hourlog = 0;
  IF currentbalance IS NULL THEN
	currentbalance=0.0;
  END IF;
  SELECT gen_upsert_BALANCELOG (hstore(ARRAY[['balance','('||oldbalance||' + '||currentbalance||')'],['yearlog',restartyear-1],['monthlog','0'],['daylog','0'],['hourlog','0']]));
  -- CREATE new counter (ràz)
  INSERT INTO yearlybalcount(ycreationtime, yyearlog, ybalance) VALUES (nowtimestamp, restartyear, 0.0);
  --propagate restart
  SELECT mmonthlog INTO restartmonth FROM monthlybalcount WHERE mcreationtime >= (SELECT MAX(mcreationtime) FROM monthlybalcount);
  SELECT restartmonthlybalance(restartyear, restartmonth);
  RETURN TRUE;
EXCEPTION
  WHEN QUERY_CANCELED OR OTHERS THEN
	RETURN FALSE;
END;
$$ LANGUAGE plpgsql;
