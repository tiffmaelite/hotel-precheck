CREATE TABLE ADDRESSES
(
  ID SERIAL,
  CLIENT_ID INTEGER NOT NULL,
  CONTACT VARCHAR(30) NOT NULL,
  STREET VARCHAR(50) NOT NULL,
  NUMBER VARCHAR(6),
  COMPLEMENTARYLINE VARCHAR(50) NOT NULL,
  CITY VARCHAR(40) NOT NULL,
  ZIPCODE VARCHAR(9),
  STATE VARCHAR(15),
  COUNTRY VARCHAR(30) NOT NULL,
  PHONE VARCHAR(13),
  CONSTRAINT PK_ADDRESSES_ID PRIMARY KEY (ID),
  CONSTRAINT UQ_ADDRESSES_CONTACTADDRESS UNIQUE (CONTACT,STREET,NUMBER,CITY,STATE,COUNTRY),
  CONSTRAINT CK_VAL_ADDRESSES_PHONE CHECK (PHONE SIMILAR TO '[\+|00][[1-9]]{3}[[:DIGIT:]]{8}')
) WITH (autovacuum_enabled = 'true', autovacuum_vacuum_threshold = 5);

--suppress_redundant_updates_trigger(); incompatible with upserts!!!
--CREATE TRIGGER z__minupdate_addresses
--BEFORE UPDATE ON addresses
--FOR EACH ROW EXECUTE PROCEDURE suppress_redundant_updates_trigger();

