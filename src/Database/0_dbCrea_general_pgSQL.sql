CONNECT "PreCheckDB.pgdb" USER 'precheck' PASSWORD 'hotel';

DROP DATABASE;

COMMIT;

CREATE DATABASE "PreCheckDB.pgdb" USER 'precheck' PASSWORD 'hotel';

COMMIT;

CONNECT "PreCheckDB.pgdb" USER 'precheck' PASSWORD 'hotel';

COMMIT;
