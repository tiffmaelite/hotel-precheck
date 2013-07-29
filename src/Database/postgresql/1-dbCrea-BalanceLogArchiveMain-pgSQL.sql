CREATE FOREIGN TABLE balancelog_archive
(
  yearlog INT,
  monthlog INT,
  daylog INT,
  hourlog INT,
  balance FLOAT
) SERVER archivesrv OPTIONS ( table_name 'balancelog', use_remote_estimate 'true', updatable 'true' );
