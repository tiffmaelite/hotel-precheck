CREATE FOREIGN TABLE balancelog_archive
(
  yearlog SMALLINT,
  monthlog SMALLINT,
  daylog SMALLINT,
  hourlog SMALLINT,
  balance DECIMAL
) SERVER archivesrv OPTIONS ( table_name 'balancelog', use_remote_estimate 'true', updatable 'true' );
