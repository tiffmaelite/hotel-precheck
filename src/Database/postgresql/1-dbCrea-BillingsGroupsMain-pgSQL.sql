CREATE TABLE BILLINGSGROUPS
(
  ID SERIAL,
  GROUP_ID INTEGER NOT NULL,
  BILLING_ID INTEGER,
  CONSTRAINT PK_BILLINGSGROUPS_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_BILLINGSGROUPS_BILLINGID UNIQUE (billing_id)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_billingsgroups
--BEFORE UPDATE ON billingsgroups
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();

--ALTER TABLE BILLINGSGROUPS ADD CONSTRAINT FK_BILLINGSGR_GROUP FOREIGN KEY (GROUP_ID) REFERENCES GROUPS_ARCHIVE (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,

CREATE OR REPLACE FUNCTION  fkbillingsgroupsreferencesgroupsarchives() RETURNS TRIGGER AS $$
BEGIN
IF (NOT EXISTS (SELECT 1 FROM GROUPS_ARCHIVE WHERE ID = NEW.GROUP_ID)) THEN
RAISE EXCEPTION 'Foreign key exception!';
END IF;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tr_fkbillingsgroupsreferencesgroupsarchives BEFORE INSERT OR UPDATE ON billingsgroups
FOR EACH ROW
EXECUTE PROCEDURE fkbillingsgroupsreferencesgroupsarchives();





CREATE TABLE TRAINING_BILLINGSGROUPS
(
  ID SERIAL,
  GROUP_ID INTEGER NOT NULL,
  BILLING_ID INTEGER,
  CONSTRAINT PK_TRAININGBILLINGSGROUPS_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_TRAININGBILLINGSGROUPS_BILLINGID UNIQUE (billing_id)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_trainingbillingsgroups
--BEFORE UPDATE ON training_billingsgroups
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();

--ALTER TABLE TRAINING_BILLINGSGROUPS ADD CONSTRAINT FK_TRAININGBILLINGSGR_GROUP FOREIGN KEY (GROUP_ID) REFERENCES GROUPS_ARCHIVE (ID) ON UPDATE NO ACTION ON DELETE NO ACTION,

CREATE OR REPLACE FUNCTION  fktrainingbillingsgroupsreferencesgroupsarchives() RETURNS TRIGGER AS $$
BEGIN
IF (NOT EXISTS (SELECT 1 FROM GROUPS_ARCHIVE WHERE ID = NEW.GROUP_ID)) THEN
RAISE EXCEPTION 'Foreign key exception!';
END IF;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER tr_fktrainingbillingsgroupsreferencesgroupsarchives BEFORE INSERT OR UPDATE ON training_billingsgroups
FOR EACH ROW
EXECUTE PROCEDURE fktrainingbillingsgroupsreferencesgroupsarchives();
