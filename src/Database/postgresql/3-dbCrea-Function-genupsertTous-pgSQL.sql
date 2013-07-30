CREATE OR REPLACE FUNCTION  gen_upsert(tablename VARCHAR, updatestring VARCHAR, wherecondition VARCHAR, returningField VARCHAR DEFAULT NULL)
RETURNS VARCHAR
AS $main$
DECLARE
  dynfunc VARCHAR;
  --dyntrig VARCHAR;
BEGIN
  --dynfunc='CREATE OR REPLACE FUNCTION  genupsert_'||tablename||'() RETURNS TRIGGER AS $inner$ BEGIN ';
  dynfunc='CREATE OR REPLACE FUNCTION  genupsert_'||tablename||'(newinput hstore) RETURNS VOID AS $inner$ BEGIN ';
  dynfunc=dynfunc||' WITH upsert AS ( UPDATE '||tablename||' SET '||regexp_replace(regexp_replace(updatestring,'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1'' ','ig')||' WHERE '||regexp_replace(regexp_replace(wherecondition,'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1'' ','ig')||' RETURNING '||tablename||'.* ) ';
  dynfunc=dynfunc||' INSERT INTO '||tablename||' (SELECT * FROM '||tablename||' WHERE NOT EXISTS (SELECT 1 FROM upsert b WHERE '||regexp_replace(wherecondition,'new','b','ig')||')) ';
  IF returningField IS NOT NULL THEN
	dynfunc=dynfunc||' RETURNING '||returningField||' ';
  END IF;
  --dynfunc=dynfunc||' RETURN NULL; END; $inner$ LANGUAGE plpgsql; ';
  dynfunc=dynfunc||'; END; $inner$ LANGUAGE plpgsql; ';

	EXECUTE dynfunc;

	--dyntrig='CREATE TRIGGER z_genupsert'||tablename||' BEFORE INSERT ON '||tablename||'	FOR EACH ROW WHEN (pg_trigger_depth() = 0) EXECUTE PROCEDURE genupsert_'||tablename||'();';

	--EXECUTE dyntrig;

 RETURN dynfunc;
END;
$main$ LANGUAGE plpgsql
VOLATILE;
