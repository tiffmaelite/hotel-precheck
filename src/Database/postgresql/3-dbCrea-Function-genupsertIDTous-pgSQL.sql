CREATE OR REPLACE FUNCTION  gen_upsertID(tablename VARCHAR, returningField VARCHAR DEFAULT NULL)
RETURNS VARCHAR
AS $main$
DECLARE
  dynfunc VARCHAR;
  col RECORD;
  updatestring VARCHAR;
BEGIN
updatestring=' SET ';
 FOR col IN SELECT column_name FROM information_schema.columns WHERE table_name=tablename AND column_name NOT ILIKE 'id%' LOOP
	updatestring=updatestring||' '||col.column_name||'=newinput -> '''||col.column_name||''', ';
 END LOOP;
  updatestring=trim(trailing ', ' from updatestring);

  dynfunc='CREATE OR REPLACE FUNCTION  genupsertID_'||tablename||'(newinput hstore, knownid integer DEFAULT 0) RETURNS VOID AS $inner$ BEGIN ';
  dynfunc=dynfunc||' WITH upsert AS ( UPDATE '||tablename||' '||updatestring||' WHERE id=knownid RETURNING '||tablename||'.* ) ';
  dynfunc=dynfunc||' INSERT INTO '||tablename||' (SELECT * FROM '||tablename||' WHERE NOT EXISTS (SELECT 1 FROM upsert b WHERE id=knownid)) ';
  IF returningField IS NOT NULL THEN
	dynfunc=dynfunc||' RETURNING '||returningField||' ';
  END IF;
  dynfunc=dynfunc||' ; END; $inner$ LANGUAGE plpgsql; ';

	EXECUTE dynfunc;
 RETURN dynfunc;
END;
$main$ LANGUAGE plpgsql
VOLATILE;


CREATE OR REPLACE FUNCTION  genall_upsertID()
RETURNS VOID
AS $main$
DECLARE
tablenames RECORD;
newfunc VARCHAR;
BEGIN
 FOR tablenames IN SELECT table_name FROM information_schema.tables WHERE table_schema!='information_schema' AND table_schema!='pg_catalog' AND table_type='BASE TABLE' LOOP
	SELECT INTO newfunc gen_upsertID(tablenames.table_name);
	EXECUTE newfunc;
  END LOOP;
END;
$main$ LANGUAGE plpgsql
VOLATILE;
