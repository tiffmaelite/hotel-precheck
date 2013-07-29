CREATE TRIGGER tr_registercharging AFTER UPDATE ON chargedservices
FOR EACH ROW
WHEN ((NEW.quantity IS NOT NULL) AND (NEW.quantity > 0))
EXECUTE PROCEDURE incrementhourlycounterbychargedservice();
