CONNECT TO "PreCheckDB" AS precheck-hotel USER 'precheck' USING 'hotel';

COMMIT;


CREATE OR ALTER FUNCTION RESTARTYEARLYBALANCE ( RESTARTYEAR INTEGER )
AS '
DECLARE VARIABLE NOWTIMESTAMP TIMESTAMP,
DECLARE VARIABLE OLDBALANCE DECIMAL,
DECLARE VARIABLE CURRENTBALANCE DECIMAL;
BEGIN
NOWTIMESTAMP = CURRENT_TIMESTAMP;
OLBALANCE = 0.0;
CURRENTBALANCE = 0.0;
SELECT BALANCE FROM YEARLYBALANCECOUNTER WHERE YEARLOG = (RESTARTYEAR-1) INTO OLDBALANCE;
IF OLDBALANCE IS NULL THEN
	OLDBALANCE = 0.0;
END IF;
SELECT BALANCE FROM BALANCELOG WHERE YEARLOG = (RESTARTYEAR-1) INTO CURRENTBALANCE;
IF CURRENTBALANCE IS NOT NULL THEN
	UPDATE BALANCELOG SET BALANCE = (OLDBALANCE + CURRENTBALANCE) WHERE YEARLOG =(RESTARTYEAR-1);
ELSE
INSERT INTO BALANCELOG(YEARLOG, MONTHLOG, DAYLOG, HOURLOG, BALANCE) VALUES ((RESTARTYEAR-1), 0, 0, 0, OLDBALANCE);
END IF;
-- CREATE new counter (ràz)
INSERT INTO YEARLYBALANCECOUNTER(CREATIONTIME, YEARLOG, BALANCE) VALUES (NOWTIMESTAMP, RESTARTYEAR, 0);
END;
' LANGUAGE SQL;

CREATE OR ALTER FUNCTION RESTARTMONTHLYBALANCE (RESTARTYEAR INT, RESTARTMONTH INT)
AS '
DECLARE VARIABLE PREVIOUSYEAR INT,
DECLARE VARIABLE NOWTIMESTAMP TIMESTAMP,
DECLARE VARIABLE OLDBALANCE DECIMAL,
DECLARE VARIABLE CURRENTBALANCE DECIMAL;
BEGIN
NOWTIMESTAMP = CURRENT_TIMESTAMP;
OLBALANCE = 0.0;
CURRENTBALANCE = 0.0;
IF RESTARTMONTH = 1 THEN
PREVIOUSYEAR = RESTARTYEAR-1;
ELSE
PREVIOUSYEAR = RESTARTYEAR;
END IF;
SELECT BALANCE FROM MONTHLYBALANCECOUNTER WHERE YEARLOG = PREVIOUSYEAR AND MONTHLOG = (RESTARTMONTH-1) INTO OLDBALANCE;
IF OLDBALANCE IS NULL THEN
	OLDBALANCE = 0.0;
END IF;
SELECT BALANCE FROM BALANCELOG WHERE YEARLOG = PREVIOUSYEAR AND MONTHLOG = (RESTARTMONTH-1) INTO CURRENTBALANCE;
IF CURRENTBALANCE IS NOT NULL THEN
	UPDATE BALANCELOG SET BALANCE = (OLDBALANCE + CURRENTBALANCE) WHERE YEARLOG = PREVIOUSYEAR AND MONTHLOG = (RESTARTMONTH-1);
ELSE
INSERT INTO BALANCELOG(YEARLOG, MONTHLOG, DAYLOG, HOURLOG, BALANCE) VALUES (PREVIOUSYEAR, (RESTARTMONTH-1), 0, 0, OLDBALANCE);
END IF;
-- CREATE new counter (ràz)
INSERT INTO MONTHLYBALANCECOUNTER(CREATIONTIME, YEARLOG, MONTHLOG, BALANCE) VALUES (NOWTIMESTAMP, RESTARTYEAR, RESTARTMONTH, 0);
END;
' LANGUAGE SQL;


CREATE OR ALTER FUNCTION RESTARTDAILYBALANCE (RESTARTYEAR INT, RESTARTMONTH INT, RESTARTDAY INT)
AS '
DECLARE VARIABLE PREVIOUSYEAR INT;
DECLARE VARIABLE PREVIOUSMONTH INT;
DECLARE VARIABLE NOWTIMESTAMP TIMESTAMP;
DECLARE VARIABLE OLDBALANCE DECIMAL;
DECLARE VARIABLE CURRENTBALANCE DECIMAL;
BEGIN
NOWTIMESTAMP = CURRENT_TIMESTAMP;
OLBALANCE = 0.0;
CURRENTBALANCE = 0.0;
IF RESTARTMONTH = 1 THEN
PREVIOUSYEAR = RESTARTYEAR-1;
ELSE
PREVIOUSYEAR = RESTARTYEAR;
END IF;
IF :RESTARTDAY = 1 THEN
PREVIOUSMONTH = RESTARTMONTH-1;
ELSE
PREVIOUSMONTH = RESTARTMONTH;
END IF;
SELECT BALANCE FROM DAYBALANCECOUNTER WHERE YEARLOG = PREVIOUSYEAR AND MONTHLOG = PREVIOUSMONTH AND DAYLOG = (RESTARTDAY-1) INTO OLDBALANCE;
IF OLDBALANCE IS NULL THEN
	OLDBALANCE = 0.0;
END IF;
SELECT BALANCE FROM BALANCELOG WHERE YEARLOG = PREVIOUSYEAR AND MONTHLOG = PREVIOUSMONTH AND DAYLOG = (RESTARTDAY-1) INTO CURRENTBALANCE;
IF :CURRENTBALANCE IS NOT NULL THEN
	UPDATE BALANCELOG SET BALANCE = (OLDBALANCE + CURRENTBALANCE) WHERE YEARLOG = PREVIOUSYEAR AND MONTHLOG = PREVIOUSMONTH AND DAYLOG = (RESTARTDAY-1);
ELSE
INSERT INTO BALANCELOG(YEARLOG, MONTHLOG, DAYLOG, HOURLOG, BALANCE) VALUES (PREVIOUSYEAR, PREVIOUSMONTH, (RESTARTDAY-1), 0, OLDBALANCE);
END IF;
-- CREATE new counter (ràz)
INSERT INTO DAYLYBALANCECOUNTER(CREATIONTIME, YEARLOG, MONTHLOG, DAYLOG, BALANCE) VALUES (NOWTIMESTAMP, RESTARTYEAR, RESTARTMONTH, RESTARTDAY, 0);
END;
' LANGUAGE SQL;


CREATE OR ALTER FUNCTION RESTARTHOURLYBALANCE (RESTARTYEAR INT, RESTARTMONTH INT, RESTARTDAY INT, RESTARTHOUR INT)
AS '
DECLARE VARIABLE PREVIOUSYEAR INT;
DECLARE VARIABLE PREVIOUSMONTH INT;
DECLARE VARIABLE PREVIOUSDAY INT;
DECLARE VARIABLE NOWTIMESTAMP TIMESTAMP;
DECLARE VARIABLE OLDBALANCE DECIMAL;
DECLARE VARIABLE CURRENTBALANCE DECIMAL;
BEGIN
NOWTIMESTAMP = CURRENT_TIMESTAMP;
OLBALANCE = 0.0;
CURRENTBALANCE = 0.0;
IF RESTARTMONTH = 1 THEN
PREVIOUSYEAR = RESTARTYEAR-1;
ELSE
PREVIOUSYEAR = :RESTARTYEAR;
END IF;
IF RESTARTDAY = 1 THEN
PREVIOUSMONTH = RESTARTMONTH-1;
ELSE
PREVIOUSMONTH = RESTARTMONTH;
END IF;
IF RESTARTHOUR = 1 THEN
PREVIOUSDAY = PREVIOUSDAY-1;
ELSE
PREVIOUSDAY = PREVIOUSDAY;
END IF;
SELECT BALANCE FROM HOURLYBALANCECOUNTER WHERE YEARLOG = PREVIOUSYEAR AND MONTHLOG = PREVIOUSMONTH AND DAYLOG = (RESTARTDAY-1) INTO OLDBALANCE;
IF OLDBALANCE IS NULL THEN
	OLDBALANCE = 0.0;
END IF;
SELECT BALANCE FROM BALANCELOG WHERE YEARLOG = PREVIOUSYEAR AND MONTHLOG = PREVIOUSMONTH AND DAYLOG = PREVIOUSDAY AND HOURLOG = (RESTARTHOUR-1) INTO CURRENTBALANCE;
IF CURRENTBALANCE IS NOT NULL THEN
BEGIN
	UPDATE BALANCELOG SET BALANCE = (OLDBALANCE + CURRENTBALANCE) WHERE YEARLOG = PREVIOUSYEAR AND MONTHLOG = PREVIOUSMONTH AND DAYLOG = :PREVIOUSDAY AND HOURLOG = (RESTARTHOUR-1);
END
ELSE
BEGIN
INSERT INTO BALANCELOG(YEARLOG, MONTHLOG, DAYLOG, HOURLOG, BALANCE) VALUES (PREVIOUSYEAR, PREVIOUSMONTH, PREVIOUSDAY, (RESTARTHOUR-1), OLDBALANCE);
END
-- CREATE new counter (ràz)
INSERT INTO HOURLYBALANCECOUNTER(CREATIONTIME, YEARLOG, MONTHLOG, DAYLOG, HOURLOG, BALANCE) VALUES (NOWTIMESTAMP, RESTARTYEAR, RESTARTMONTH, RESTARTDAY, RESTARTHOUR, 0;
END;
' LANGUAGE SQL;

CREATE OR ALTER FUNCTION INCREMENTHOURLYCOUNTERBY (SUPPLEMENT DECIMAL)
AS '
BEGIN
UPDATE HOURLYBALANCECOUNTER SET BALANCE = BALANCE+$1 WHERE CREATIONTIME >= (SELECT MAX(CREATIONTIME) FROM HOURLYBALANCECOUNTER);
END;
' LANGUAGE SQL;

CREATE OR ALTER FUNCTION INCREMENTDAYLYCOUNTERBY (SUPPLEMENT DECIMAL)
AS '
BEGIN
UPDATE DAYLYBALANCECOUNTER SET BALANCE = BALANCE+$1 WHERE CREATIONTIME >= (SELECT MAX(CREATIONTIME) FROM DAYLYBALANCECOUNTER);
END;
' LANGUAGE SQL;

CREATE OR ALTER FUNCTION INCREMENTMONTHLYCOUNTERBY (SUPPLEMENT DECIMAL)
AS '
BEGIN
UPDATE MONTHLYBALANCECOUNTER SET BALANCE = BALANCE+$1 WHERE CREATIONTIME >= (SELECT MAX(CREATIONTIME) FROM MONTHLYBALANCECOUNTER);
END;
' LANGUAGE SQL;


CREATE OR ALTER FUNCTION INCREMENTYEARLYCOUNTERBY (SUPPLEMENT DECIMAL)
AS '
BEGIN
UPDATE YEARLYBALANCECOUNTER SET BALANCE = BALANCE+$1 WHERE CREATIONTIME >= (SELECT MAX(CREATIONTIME) FROM YEARLYBALANCECOUNTER);
END;
' LANGUAGE SQL;


COMMIT;


CREATE TRIGGER TR_MONTHLOG BEFORE UPDATE ON MONTHLYBALANCECOUNTER
FOR EACH ROW
WHEN ((NEW.BALANCE IS NOT NULL) AND (NEW.BALANCE > 0))
EXECUTE INCREMENTYEARLYCOUNTERBY(new.BALANCE-old.BALANCE);


CREATE TRIGGER TR_DAYLOG BEFORE UPDATE ON DAYLYBALANCECOUNTER
FOR EACH ROW
WHEN ((NEW.BALANCE IS NOT NULL) AND (NEW.BALANCE > 0))
EXECUTE INCREMENTMONTHLYCOUNTERBY(new.BALANCE-old.BALANCE);


CREATE TRIGGER TR_HOURLOG BEFORE UPDATE ON HOURLYBALANCECOUNTER
FOR EACH ROW
WHEN ((NEW.BALANCE IS NOT NULL) AND (NEW.BALANCE > 0))
EXECUTE INCREMENTDAYLYCOUNTERBY(new.BALANCE-old.BALANCE);


CREATE TRIGGER TR_REGISTERCHARGING BEFORE UPDATE ON CHARGEDSERVICES
FOR EACH ROW
WHEN ((NEW.BALANCE IS NOT NULL) AND (NEW.BALANCE > 0))
EXECUTE INCREMENTHOURLYCOUNTERBY(NEW.CHARGEDUNITYPRICE*(1+VAT_PERCENTAGE)*NEW.QUANTITY);

COMMIT;
