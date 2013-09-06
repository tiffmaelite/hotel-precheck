CREATE OR REPLACE FUNCTION  gen_upsertmult(tablename VARCHAR, updatestrings VARCHAR[], whereconditions VARCHAR[], returningField VARCHAR DEFAULT NULL)
RETURNS VARCHAR
AS $main$
DECLARE
  dynfunc VARCHAR;
  dynsql VARCHAR;
  mult INTEGER;
  updatestring VARCHAR;
  wherecondition VARCHAR;
BEGIN
  mult=least(array_length(whereconditions,1),array_length(updatestrings,1));

  dynfunc='CREATE OR REPLACE FUNCTION  genupsert_'||tablename||'(newinput hstore) RETURNS ';
  IF returningField IS NOT NULL THEN
	dynfunc = dynfunc||' TEXT AS $inner$ DECLARE returnVar TEXT; ';
  ELSE
	dynfunc = dynfunc||' VOID AS $inner$ ';
  END IF;
  dynfunc= dynfunc||' BEGIN ';
  dynsql=' WITH ';
  FOR i IN 1..mult
  LOOP
	wherecondition=regexp_replace(regexp_replace(whereconditions[i],'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1''','ig');
	updatestring=regexp_replace(regexp_replace(updatestrings[i],'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1'' ','ig');

	dynsql=dynsql||' upsert'||i||' AS ( UPDATE '||tablename||' SET '||updatestring||' WHERE '||wherecondition||' RETURNING '||tablename||'.* ), ';
  END LOOP;
  dynsql=trim(trailing ', ' from dynsql);
  dynsql=dynsql||' INSERT INTO '||tablename||' (SELECT * FROM '||tablename||' WHERE NOT EXISTS ( ';
  FOR i IN 1..mult
  LOOP
  dynsql=dynsql||' SELECT 1 FROM  upsert'||i||' b'||i||' WHERE ('||regexp_replace(whereconditions[i],'new','b'||i,'ig')||') UNION ALL ';
  END LOOP;
  dynsql=trim(trailing 'UNION ALL ' from dynsql);
  dynsql=dynsql||' ))';
  IF returningField IS NOT NULL THEN
	--dynsql=dynsql||' RETURNING '||returningField||' INTO returnVar; ';
	dynsql=dynsql||'; SELECT '||returningField||' INTO returnVar FROM '||tablename||' WHERE ';
	FOR i IN 1..mult
	LOOP
	wherecondition=regexp_replace(regexp_replace(whereconditions[i],'new\.(\w+)(\s|,)','newinput -> ''\1''\2','ig'),'new\.(\w+)$','newinput -> ''\1''','ig');
	dynsql=dynsql||' '||wherecondition||' OR ';
	END LOOP;
	dynsql=trim(trailing 'OR ' from dynsql);
	dynsql=dynsql||';';
		dynfunc=dynfunc||' '||dynsql||' RAISE NOTICE '||quote_literal(dynsql)||'; RAISE NOTICE '' % ====> %'', hstore_to_json_loose(newinput), returnVar; RETURN CAST(returnVar AS TEXT); ';
	  ELSE
		dynfunc=dynfunc||' '||dynsql||';';
	  END IF;
	  dynfunc=dynfunc||' EXECUTE query; END; $inner$ LANGUAGE plpgsql; ';
	EXECUTE dynfunc;

 RETURN dynfunc;
END;
$main$ LANGUAGE plpgsql
VOLATILE;
