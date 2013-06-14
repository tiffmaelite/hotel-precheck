CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fbd' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;

DROP DATABASE;

COMMIT;

CREATE DATABASE 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;

CONNECT 'localhost:/home/tiff/Stage-IUT/app/hotel-precheck/src/PreCheck/Database/PreCheckDB.fdb' USER 'SYSDBA' PASSWORD 'masterkey';

COMMIT;

CREATE DOMAIN BOOLEAN AS CHAR(1) CHECK (value is null or value in ('','0', '1'));

COMMIT;
