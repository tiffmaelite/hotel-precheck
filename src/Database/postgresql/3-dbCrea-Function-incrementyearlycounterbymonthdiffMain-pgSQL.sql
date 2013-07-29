CREATE OR REPLACE FUNCTION  incrementyearlycounterbymonthdiff ()
RETURNS TRIGGER
AS $$
BEGIN
  UPDATE yearlybalancecounter SET ybalance = ybalance+(NEW.mbalance-OLD.mbalance) WHERE ycreationtime >= (SELECT MAX(ycreationtime) FROM yearlybalancecounter);
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;
