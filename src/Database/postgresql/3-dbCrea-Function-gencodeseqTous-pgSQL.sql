CREATE OR REPLACE FUNCTION gen_codeseq(tablename VARCHAR, tablecodefield VARCHAR, reftablename VARCHAR, reflabelfield VARCHAR, tablesjoinfield VARCHAR)
RETURNS VOID
AS $main$
DECLARE
  dynfunc VARCHAR;
  dyntrig VARCHAR;
BEGIN
  dynfunc='CREATE OR REPLACE FUNCTION next'||tablename||tablecodefield||'seq() RETURNS TRIGGER AS $inner$ DECLARE p_seq_name VARCHAR; DECLARE reflabel VARCHAR; DECLARE seqval BIGINT; BEGIN SELECT currval(p_seq_name) INTO seqval; IF new.'||tablecodefield||' = 0 THEN SELECT '||reflabelfield||' INTO reflabel FROM '||reftablename||' WHERE ID=new.'||tablesjoinfield||'; IF FOUND THEN p_seq_name='''||tablename||'_'||tablecodefield||'_SEQ_''||reflabel; SELECT * FROM pg_class c JOIN pg_namespace n ON n.oid = c.relnamespace WHERE c.relname = p_seq_name AND c.relkind =''S''; IF NOT FOUND THEN CREATE SEQUENCE p_seq_name; END IF; SELECT '||tablecodefield||' INTO seqval FROM '||tablename||' a WHERE NOT EXISTS (SELECT NULL FROM '||tablename||' b WHERE b.'||tablecodefield||' = a.'||tablecodefield||' + 1 AND a.'||tablecodefield||' >= seqval) ORDER BY '||tablecodefield||' LIMIT 1; SELECT setval(p_seq_name, seqval); new.'||tablecodefield||'=nextval(p_seq_name); END IF; END IF; RETURN new; END; $inner$ LANGUAGE ''plpgsql'';';
  dyntrig='CREATE TRIGGER tr_next'||tablename||tablecodefield||' BEFORE INSERT ON '||tablename||'	FOR EACH ROW EXECUTE PROCEDURE next'||tablename||tablecodefield||'seq();';

  EXPLAIN (VERBOSE true ANALYZE true FORMAT JSON) dynfunc;
  EXPLAIN (VERBOSE true ANALYZE true FORMAT JSON) dyntrig;
  ROLLBACK;

  EXECUTE dynfunc;
  EXECUTE dyntrig;

END;
$main$ LANGUAGE plpgsql
VOLATILE;

