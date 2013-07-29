CREATE FOREIGN TABLE GROUPS_ARCHIVE
(
  ID SERIAL,
  NAME VARCHAR(25) NOT NULL,
  CONTACT_ID INTEGER
) SERVER archivesrv OPTIONS ( table_name 'groups', use_remote_estimate 'true', updatable 'true' );
