CREATE OR REPLACE FUNCTION  incrementmonthlycounterbydaydiff ()
RETURNS TRIGGER
AS $$
BEGIN
  UPDATE monthlybalcount SET mbalance = mbalance+(NEW.dbalance-OLD.dbalance) WHERE mcreationtime >= (SELECT MAX(mcreationtime) FROM monthlybalcount);
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;
