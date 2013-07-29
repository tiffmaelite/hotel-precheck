CREATE TRIGGER tr_hourlog AFTER UPDATE ON hourlybalcount
FOR EACH ROW
WHEN ((NEW.hbalance IS NOT NULL) AND (NEW.hbalance > 0))
EXECUTE PROCEDURE incrementdailycounterbyhourdiff();
