CREATE OR REPLACE FUNCTION  restarthourlybalance (restartyear SMALLINT, restartmonth SMALLINT, restartday SMALLINT, restarthour SMALLINT)
RETURNS BOOLEAN
AS $$
  DECLARE previousyear SMALLINT;
  DECLARE previousmonth SMALLINT;
  DECLARE previousday SMALLINT;
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
  SELECT hbalance INTO oldbalance FROM hourlybalcount WHERE hyearlog = previousyear AND hmonthlog = previousmonth AND hdaylog =  previousday AND hhourlog = (restarthour-1);
  IF oldbalance IS NULL THEN
	oldbalance = 0.0;
  END IF;
  SELECT balance INTO currentbalance FROM balancelog_archive WHERE yearlog = previousyear AND monthlog = previousmonth AND daylog =  previousday AND hourlog = (restarthour-1);
  IF currentbalance IS NULL THEN
	currentbalance=0.0;
  END IF;
  SELECT gen_upsert_BALANCELOG (hstore(ARRAY[['balance','('||oldbalance||' + '||currentbalance||')'],['yearlog',previousyear],['monthlog',previousmonth],['daylog',previousday],['hourlog',restarthour-1]]));

  -- CREATE new counter (ràz)
  INSERT INTO hourlybalcount(hcreationtime, hyearlog, hmonthlog, hdaylog, hhourlog, hbalance) VALUES (nowtimestamp, restartyear, restartmonth, restartday, restarthour, 0.0);
  RETURN TRUE;
EXCEPTION
  WHEN QUERY_CANCELED OR OTHERS THEN
	RETURN FALSE;
END;
$$ LANGUAGE plpgsql;
