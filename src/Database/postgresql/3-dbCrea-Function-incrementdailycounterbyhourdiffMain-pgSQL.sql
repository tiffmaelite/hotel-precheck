CREATE OR REPLACE FUNCTION  incrementdailycounterbyhourdiff ()
RETURNS TRIGGER
AS $$
BEGIN
  UPDATE dailybalancecounter SET dbalance = CAST(dbalance+(NEW.hbalance-OLD.hbalance) AS DECIMAL) WHERE dcreationtime >= (SELECT MAX(dcreationtime) FROM dailybalancecounter);
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;
