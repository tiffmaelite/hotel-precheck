CREATE TABLE BILLS
(
  ID SERIAL,
  BILLING_ID INTEGER NOT NULL,
  BILLINGBILLID INTEGER NOT NULL,
  BILLTYPE_ID INTEGER NOT NULL,
  NOTE VARCHAR(255),
  CONSTRAINT PK_BILLS_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_BILLS_IDBILLID UNIQUE (BILLING_ID,BILLINGBILLID)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_bills
--BEFORE UPDATE ON bills
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();


CREATE TABLE TRAINING_BILLS
(
  ID SERIAL,
  BILLING_ID INTEGER NOT NULL,
  BILLINGBILLID INTEGER NOT NULL,
  BILLTYPE_ID INTEGER NOT NULL,
  NOTE VARCHAR(255),
  CONSTRAINT PK_TRAININGBILLS_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_TRAININGBILLS_IDBILLID UNIQUE (BILLING_ID,BILLINGBILLID)
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_TRAININGbills
--BEFORE UPDATE ON TRAINING_BILLS
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();
