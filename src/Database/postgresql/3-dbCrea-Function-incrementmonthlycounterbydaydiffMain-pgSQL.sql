CREATE OR REPLACE FUNCTION  incrementmonthlycounterbydaydiff ()
RETURNS TRIGGER
AS $$
BEGIN
  UPDATE monthlybalancecounter SET mbalance = mbalance+(NEW.dbalance-OLD.dbalance) WHERE mcreationtime >= (SELECT MAX(mcreationtime) FROM monthlybalancecounter);
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;
