CREATE FOREIGN TABLE NATIONALITIES_ARCHIVE
(
ID SERIAL,
COUNTRY VARCHAR(511) NOT NULL,
ISOCODE VARCHAR(2) NOT NULL,
LONGISOCODE VARCHAR(3) NOT NULL,
CODE VARCHAR(3) NOT NULL
) SERVER archivesrv OPTIONS ( table_name 'nationalities', use_remote_estimate 'true', updatable 'true' );
