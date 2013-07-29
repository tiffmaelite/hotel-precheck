CREATE OR REPLACE FUNCTION  incrementhourlycounterbychargedservice ()
RETURNS TRIGGER
AS $$
BEGIN
  UPDATE hourlybalancecounter SET hbalance = hbalance+(NEW.chargedunitprice*(1+vat_percentage)*NEW.quantity) WHERE hcreationtime >= (SELECT MAX(hcreationtime) FROM hourlybalancecounter);
  RETURN NEW;
END;
$$ LANGUAGE plpgsql;
