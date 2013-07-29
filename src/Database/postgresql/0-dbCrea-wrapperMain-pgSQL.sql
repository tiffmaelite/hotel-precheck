-- Create a server-to-server link after loading postgres_fdw extension:
	CREATE SERVER archivesrv FOREIGN DATA WRAPPER postgres_fdw OPTIONS ( host '/var/run/postgresql', port '5434', dbname 'precheckarchivesdb');
-- Create a mapping for local database users to remote database users:
	CREATE USER MAPPING FOR precheck SERVER archivesrv OPTIONS ( user 'precheck', password 'hotel' );


-- Finally, link to the tables on the remote server:
-- CREATE FOREIGN TABLE clients_archive (aid int, bid int, abalance int, filler char(84)) SERVER archivesrv OPTIONS ( table_name 'clients' );
-- Queries can be run against the tables on the attached server, including writing to it, just as if it were a table on the local server:
-- INSERT INTO clients_archive ( aid, bid, abalance ) VALUES ( 10000000, 5, 100 );
