CREATE OR REPLACE FUNCTION  incrementhourlycounterbychargedservice ()
RETURNS TRIGGER
AS $$
BEGIN
  UPDATE hourlybalcount SET hbalance = hbalance+(NEW.chargedunitprice*(1+vat_percentage)*NEW.quantity) WHERE hcreationtime >= (SELECT MAX(hcreationtime) FROM hourlybalcount);
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;
