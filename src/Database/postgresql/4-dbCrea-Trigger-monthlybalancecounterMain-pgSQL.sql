CREATE TRIGGER tr_monthlog AFTER UPDATE ON monthlybalcount
FOR EACH ROW
WHEN ((NEW.mbalance IS NOT NULL) AND (NEW.mbalance > 0))
EXECUTE PROCEDURE incrementyearlycounterbymonthdiff();
