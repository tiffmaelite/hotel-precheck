CREATE FOREIGN TABLE NATIONALITIES_ARCHIVE
(
  ID SERIAL,
  CODE VARCHAR(3) NOT NULL,
  COUNTRY VARCHAR(100) NOT NULL,
  NAME VARCHAR(50) NOT NULL
) SERVER archivesrv OPTIONS ( table_name 'nationalities', use_remote_estimate 'true', updatable 'true' );
