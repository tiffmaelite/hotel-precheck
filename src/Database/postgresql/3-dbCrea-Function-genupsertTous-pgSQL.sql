CREATE OR REPLACE FUNCTION  gen_upsert(tablename VARCHAR, updatestring VARCHAR, wherecondition VARCHAR, returningField VARCHAR DEFAULT NULL)
RETURNS VARCHAR
AS $main$
DECLARE
  dynfunc VARCHAR;
  dynsql VARCHAR;
BEGIN
  dynfunc='CREATE OR REPLACE FUNCTION  genupsert_'||tablename||'(newinput hstore) RETURNS ';
  IF returningField IS NOT NULL THEN
	dynfunc = dynfunc||' TEXT AS $inner$ DECLARE returnVar TEXT; ';
  ELSE
	dynfunc = dynfunc||' VOID AS $inner$ ';
  END IF;
  dynfunc= dynfunc||' BEGIN ';
  dynsql = 'WITH upsert AS ( UPDATE '||tablename||' SET '||regexp_replace(regexp_replace(updatestring,'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1'' ','ig')||' WHERE '||regexp_replace(regexp_replace(wherecondition,'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1'' ','ig')||' RETURNING '||tablename||'.* ) ';
  dynsql=dynsql||' INSERT INTO '||tablename||' (SELECT * FROM '||tablename||' WHERE NOT EXISTS (SELECT 1 FROM upsert b WHERE '||regexp_replace(wherecondition,'new','b','ig')||')) ';
  IF returningField IS NOT NULL THEN
	--dynsql=dynsql||' RETURNING '||returningField||' INTO returnVar; ';
	dynsql=dynsql||'; SELECT '||returningField||' INTO returnVar FROM '||tablename||' WHERE '||regexp_replace(regexp_replace(wherecondition,'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1'' ','ig')||';';
	dynfunc=dynfunc||' '||dynsql||'  RAISE NOTICE '||quote_literal(dynsql)||'; RAISE NOTICE '' % ====> %'', hstore_to_json_loose(newinput), returnVar; RETURN CAST(returnVar AS TEXT); ';
  ELSE
	dynfunc=dynfunc||' '||dynsql||';';
  END IF;
  dynfunc=dynfunc||' EXECUTE query; END; $inner$ LANGUAGE plpgsql; ';
	EXECUTE dynfunc;
 RETURN dynfunc;
END;
$main$ LANGUAGE plpgsql
VOLATILE;
