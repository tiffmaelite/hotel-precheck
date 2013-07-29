CREATE TABLE billingsclients
(
  id SERIAL,
  client_id INTEGER NOT NULL,
  billing_id INTEGER,
  CONSTRAINT PK_BILLINGSCLIENTS_ID PRIMARY KEY (id),
  CONSTRAINT UQ_BILLINGSCLIENTS_BILLINGID UNIQUE (billing_id)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_billingsclients
--BEFORE UPDATE ON billingsclients
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();


--ALTER TABLE BILLINGSCLIENTS ADD CONSTRAINT FK_BILLINGSCL_CLIENT FOREIGN KEY (CLIENT_ID) REFERENCES CLIENTS_ARCHIVE (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;

CREATE OR REPLACE FUNCTION  fkbillingsclientsreferencesclientsarchives() RETURNS TRIGGER AS $$
BEGIN
IF (NOT EXISTS (SELECT 1 FROM CLIENTS_ARCHIVE WHERE ID = NEW.CLIENT_ID)) THEN
RAISE EXCEPTION 'Foreign key exception!';
END IF;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tr_fkbillingsclientsreferencesclientsarchives BEFORE INSERT OR UPDATE ON billingsclients
FOR EACH ROW
EXECUTE PROCEDURE fkbillingsclientsreferencesclientsarchives();




CREATE TABLE training_billingsclients
(
  id SERIAL,
  client_id INTEGER NOT NULL,
  billing_id INTEGER,
  CONSTRAINT PK_TRAININGBILLINGSCLIENTS_ID PRIMARY KEY (id),
  CONSTRAINT UQ_TRAININGBILLINGSCLIENTS_BILLINGID UNIQUE (billing_id)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_trainingbillingsclients
--BEFORE UPDATE ON training_billingsclients
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();


--ALTER TABLE TRAINING_BILLINGSCLIENTS ADD CONSTRAINT FK_TRAININGBILLINGSCL_CLIENT FOREIGN KEY (CLIENT_ID) REFERENCES CLIENTS_ARCHIVE (ID) ON UPDATE NO ACTION ON DELETE NO ACTION;
CREATE OR REPLACE FUNCTION  fktrainingbillingsclientsreferencesclientsarchives() RETURNS TRIGGER AS $$
BEGIN
IF  (NOT EXISTS (SELECT 1 FROM CLIENTS_ARCHIVE WHERE ID = NEW.CLIENT_ID)) THEN
RAISE EXCEPTION 'Foreign key exception!';
END IF;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tr_fktrainingbillingsclientsreferencesclientsarchives BEFORE INSERT OR UPDATE ON training_billingsclients
FOR EACH ROW
EXECUTE PROCEDURE fktrainingbillingsclientsreferencesclientsarchives();
