CONNECT "PreCheckDB.fdb" USER 'precheck' PASSWORD 'hotel';

DROP DATABASE;

COMMIT;

CREATE DATABASE "PreCheckDB.fdb" USER 'precheck' PASSWORD 'hotel';

COMMIT;

CONNECT "PreCheckDB.fdb" USER 'precheck' PASSWORD 'hotel';

CREATE DOMAIN BOOLEAN AS CHAR(1) CHECK (value is null or value in ('','0', '1'));

COMMIT;
