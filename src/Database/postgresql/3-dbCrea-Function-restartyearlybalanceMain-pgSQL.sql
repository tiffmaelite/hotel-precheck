CREATE OR REPLACE FUNCTION  restartyearlybalance ( restartyear INTEGER )
RETURNS VOID
AS $$
  DECLARE nowtimestamp TIMESTAMP;
  DECLARE oldbalance DECIMAL;
  DECLARE currentbalance DECIMAL;
BEGIN
  nowtimestamp = CURRENT_TIMESTAMP;
  oldbalance = 0.0;
  currentbalance = 0.0;
  SELECT ybalance FROM yearlybalancecounter WHERE yyearlog = (restartyear-1) INTO oldbalance;
  IF oldbalance IS NULL THEN
	oldbalance = 0.0;
  END IF;
  SELECT balance FROM balancelog_archive WHERE yearlog = (restartyear-1) INTO currentbalance;
  IF currentbalance IS NOT NULL THEN
	UPDATE balancelog_archive SET balance = (oldbalance + currentbalance) WHERE yearlog =(restartyear-1);
  ELSE
	INSERT INTO balancelog_archive(yearlog, monthlog, daylog, hourlog, balance) VALUES ((restartyear-1), 0, 0, 0, oldbalance);
  END IF;
  -- CREATE new counter (ràz)
  INSERT INTO yearlybalancecounter(ycreationtime, yyearlog, ybalance) VALUES (nowtimestamp, restartyear, 0.0);
END;
$$ LANGUAGE plpgsql;
