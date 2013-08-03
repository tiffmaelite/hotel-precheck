CREATE OR REPLACE FUNCTION gen_codeseq(tablename VARCHAR, tablecodefield VARCHAR, reftablename VARCHAR, reflabelfield VARCHAR, tablesjoinfield VARCHAR)
RETURNS VARCHAR
AS $main$
DECLARE
  dynfunc VARCHAR;
  dyntrig VARCHAR;
BEGIN
  dynfunc='CREATE OR REPLACE FUNCTION next'||tablename||tablecodefield||'seq() RETURNS TRIGGER AS $inner$ DECLARE p_seq_name VARCHAR; DECLARE reflabel VARCHAR; DECLARE seqval BIGINT; BEGIN RAISE NOTICE ''next seq on '||tablename||'''; IF new.'||tablecodefield||' IS NULL OR new.'||tablecodefield||' = 0 THEN SELECT '||reflabelfield||' INTO reflabel FROM '||reftablename||' WHERE ID=new.'||tablesjoinfield||'; IF FOUND THEN p_seq_name='''||tablename||'_'||tablecodefield||'_SEQ_''||reflabel; SELECT currval(p_seq_name) INTO seqval; SELECT * FROM pg_class c JOIN pg_namespace n ON n.oid = c.relnamespace WHERE c.relname = p_seq_name AND c.relkind =''S''; IF NOT FOUND THEN CREATE SEQUENCE p_seq_name; END IF; SELECT '||tablecodefield||' INTO seqval FROM '||tablename||' a WHERE NOT EXISTS (SELECT NULL FROM '||tablename||' b WHERE b.'||tablecodefield||' = a.'||tablecodefield||' + 1 AND a.'||tablecodefield||' >= seqval) ORDER BY '||tablecodefield||' LIMIT 1; END IF; SELECT setval(p_seq_name, seqval); new.'||tablecodefield||':=nextval(p_seq_name);  END IF; RAISE NOTICE ''next seq %; next id %'', new.'||tablecodefield||', new.id ;RETURN new; END; $inner$ LANGUAGE ''plpgsql'';';
  dyntrig='CREATE TRIGGER tr_next'||tablename||tablecodefield||' BEFORE INSERT ON '||tablename||' FOR EACH ROW EXECUTE PROCEDURE next'||tablename||tablecodefield||'seq();';

RAISE NOTICE 'dynfunc: %', dynfunc;
RAISE NOTICE 'dyntrig: %', dyntrig;
  EXECUTE dynfunc;
  EXECUTE dyntrig;

  RETURN dynfunc||' '||dyntrig;

END;
$main$ LANGUAGE plpgsql
VOLATILE;

