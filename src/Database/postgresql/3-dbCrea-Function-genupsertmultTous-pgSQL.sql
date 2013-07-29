CREATE OR REPLACE FUNCTION  gen_upsertmult(tablename VARCHAR, updatestrings VARCHAR[], whereconditions VARCHAR[])
RETURNS VARCHAR
AS $main$
DECLARE
  dynfunc VARCHAR;
  --dyntrig VARCHAR;
  mult INTEGER;
  updatestring VARCHAR;
  wherecondition VARCHAR;
BEGIN
  mult=least(array_length(whereconditions,1),array_length(updatestrings,1));
  --dynfunc='CREATE OR REPLACE FUNCTION  genupsert_'||tablename||'() RETURNS TRIGGER AS $inner$ BEGIN WITH ';
  dynfunc='CREATE OR REPLACE FUNCTION  genupsert_'||tablename||'(newinput hstore) RETURNS VOID AS $inner$ BEGIN WITH ';
  FOR i IN 1..mult
  LOOP
  wherecondition=regexp_replace(regexp_replace(whereconditions[i],'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1''','ig');
  updatestring=regexp_replace(regexp_replace(updatestrings[i],'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1'' ','ig');

  dynfunc=dynfunc||' upsert'||i||' AS ( UPDATE '||tablename||' SET '||updatestring||' WHERE '||wherecondition||' RETURNING '||tablename||'.* ), ';
  END LOOP;
  dynfunc=trim(trailing ', ' from dynfunc);
  dynfunc=dynfunc||' INSERT INTO '||tablename||' (SELECT * FROM '||tablename||' WHERE NOT EXISTS ( ';
  FOR i IN 1..mult
  LOOP
  dynfunc=dynfunc||' SELECT 1 FROM  upsert'||i||' b'||i||' WHERE ('||regexp_replace(whereconditions[i],'new','b'||i,'ig')||') UNION ALL ';
  END LOOP;
  dynfunc=trim(trailing 'UNION ALL ' from dynfunc);
  --dynfunc=dynfunc||' )); RETURN NULL; END; $inner$ LANGUAGE plpgsql; ';
  dynfunc=dynfunc||' )); END; $inner$ LANGUAGE plpgsql; ';

	EXECUTE dynfunc;

	--dyntrig='CREATE TRIGGER z_genupsert'||tablename||' BEFORE INSERT ON '||tablename||'	FOR EACH ROW WHEN (pg_trigger_depth() = 0) EXECUTE PROCEDURE genupsert_'||tablename||'();';
	--EXECUTE dyntrig;

 RETURN dynfunc;
END;
$main$ LANGUAGE plpgsql
VOLATILE;
