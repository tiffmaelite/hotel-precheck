  CONNECT "PreCheckDB.fdb" USER 'precheck' PASSWORD 'hotel';

  DROP DATABASE;

  COMMIT;

  CONNECT "PreCheckArchivesDB.fdb" USER 'precheck' PASSWORD 'hotel';

  DROP DATABASE;

  COMMIT;

  CREATE DATABASE "PreCheckDB.fbdb" USER 'precheck' PASSWORD 'hotel';

  COMMIT;

  CREATE DATABASE "PreCheckArchivesDB.fbdb" USER 'precheck' PASSWORD 'hotel';

  COMMIT;
