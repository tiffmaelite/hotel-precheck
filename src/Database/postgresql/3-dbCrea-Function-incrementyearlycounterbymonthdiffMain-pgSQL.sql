CREATE OR REPLACE FUNCTION  incrementyearlycounterbymonthdiff ()
RETURNS TRIGGER
AS $$
BEGIN
  UPDATE yearlybalcount SET ybalance = ybalance+(NEW.mbalance-OLD.mbalance) WHERE ycreationtime >= (SELECT MAX(ycreationtime) FROM yearlybalcount);
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;
