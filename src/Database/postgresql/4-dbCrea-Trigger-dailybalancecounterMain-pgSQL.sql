CREATE TRIGGER tr_daylog AFTER UPDATE ON dailybalcount
FOR EACH ROW
WHEN ((NEW.dbalance IS NOT NULL) AND (NEW.dbalance > 0))
EXECUTE PROCEDURE incrementmonthlycounterbydaydiff();
