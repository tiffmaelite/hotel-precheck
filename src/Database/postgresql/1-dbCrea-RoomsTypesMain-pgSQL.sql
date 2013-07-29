CREATE TABLE ROOMSTYPES
(
  ID SERIAL,
  LABEL VARCHAR(20) NOT NULL,
  DESCRIPTION VARCHAR(255),
  PRICEMIN FLOAT NOT NULL,
  PRICEMAX FLOAT,
  CONSTRAINT PK_ROOMSTYPES_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_ROOMSTYPES_NAME UNIQUE (LABEL)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);
--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_roomstypes
--BEFORE UPDATE ON roomstypes
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();

CREATE OR REPLACE FUNCTION  upsert_ROOMSTYPES()
RETURNS trigger
AS $$
BEGIN
 LOOP
	-- first try to update the key
UPDATE ROOMSTYPES SET DESCRIPTION=new.DESCRIPTION, PRICEMIN=NEW.PRICEMIN, PRICEMAX=NEW.PRICEMAX WHERE LABEL=new.LABEL;
IF (FOUND) THEN --updated, do nothing
RETURN NULL;
END IF;
-- not there, so try to insert the key
-- if someone else inserts the same key concurrently,
-- we could get a unique-key failure
  BEGIN
INSERT INTO ROOMSTYPES(LABEL, DESCRIPTION, PRICEMIN, PRICEMAX) VALUES(NEW.LABEL, NEW.DESCRIPTION, NEW.PRICEMIN, NEW.PRICEMAX);
RETURN NEW;
EXCEPTION WHEN unique_violation THEN
	 -- do nothing, and loop to try the UPDATE again
 END;
END LOOP;
END;
$$ LANGUAGE plpgsql;


--CREATE TRIGGER z__upsertROOMSTYPES
--BEFORE INSERT ON ROOMSTYPES
--FOR EACH ROW WHEN (pg_trigger_depth() = 0) EXECUTE PROCEDURE upsert_ROOMSTYPES();
