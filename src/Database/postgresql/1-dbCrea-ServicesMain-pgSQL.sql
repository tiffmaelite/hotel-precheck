CREATE TABLE SERVICES
(
  ID SERIAL,
  SERVICETYPE_ID INTEGER NOT NULL,
  NAME VARCHAR(100) NOT NULL,
  ISAVAILABLE BOOLEAN DEFAULT '1'  NOT NULL,
  CONSTRAINT PK_SERVICES_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_SERVICES_NAME UNIQUE (NAME)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_SERVICES
--BEFORE UPDATE ON SERVICES
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();

CREATE OR REPLACE FUNCTION  upsert_SERVICES()
RETURNS trigger
AS $$
BEGIN
 LOOP
	-- first try to update the key
UPDATE SERVICES SET SERVICETYPE_ID=new.SERVICETYPE_ID, ISAVAILABLE=NEW.ISAVAILABLE WHERE NAME=new.NAME;
IF (FOUND) THEN --updated, do nothing
RETURN NULL;
END IF;
-- not there, so try to insert the key
-- if someone else inserts the same key concurrently,
-- we could get a unique-key failure
  BEGIN
INSERT INTO SERVICES(NAME, SERVICETYPE_ID,ISAVAILABLE) VALUES(NEW.NAME, NEW.SERVICETYPE_ID, NEW.ISAVAILABLE);
RETURN NEW;
EXCEPTION WHEN unique_violation THEN
	 -- do nothing, and loop to try the UPDATE again
 END;
END LOOP;
END;
$$ LANGUAGE plpgsql;


--CREATE TRIGGER z__upsertSERVICES
--BEFORE INSERT ON SERVICES
--FOR EACH ROW WHEN (pg_trigger_depth() = 0) EXECUTE PROCEDURE upsert_SERVICES();
