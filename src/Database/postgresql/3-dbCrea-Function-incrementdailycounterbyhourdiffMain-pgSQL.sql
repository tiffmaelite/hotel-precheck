CREATE OR REPLACE FUNCTION  incrementdailycounterbyhourdiff ()
RETURNS TRIGGER
AS $$
BEGIN
  UPDATE dailybalcount SET dbalance = CAST(dbalance+(NEW.hbalance-OLD.hbalance) AS DECIMAL) WHERE dcreationtime >= (SELECT MAX(dcreationtime) FROM dailybalcount);
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;
