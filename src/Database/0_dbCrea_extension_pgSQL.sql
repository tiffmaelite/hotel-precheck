-- PL/pgSQL code to create pivot tables with automatic column names
-- Eric Minikel, CureFFI.org - 2013-03-19
-- Modified by Tiffany Grenier (2013-07-08) for taking SQL types in other database

-- prerequisite: install the tablefunc module
create extension tablefunc;

-- tablename: name of source table you want to pivot
-- rowc: the name of the column in source table you want to be the rows
-- colc: the name of the column in source table you want to be the columns
-- cellc: an aggregate expression determining how the cell values will be created
-- celldatatype: desired data type for the cells
create or replace function pivotcode (tablename varchar, rowc varchar, colc varchar, cellc varchar, celldatatypessource varchar, celldatatypestable varchar)
 returns varchar language plpgsql as $$
declare
	dynsql1 varchar;
	dynsql2 varchar;
	columnlist varchar;
begin
-- 1. retrieve list of column names and types.
	--dynsql1 = 'select string_agg(distinct ''_''||'||colc||'||'' '||celldatatype||''','','' order by ''_''||'||colc||'||'' '||celldatatype||''') from '||tablename||';';
	dynsql1 = 'select string_agg('||tablename||'.'||colc ||'||'' ''||'||celldatatypestable||'.'||celldatatypessource||','', '') from '||celldatatypestable||' join '||tablename||' on '||tablename||'.'||colc||' = '||celldatatypestable||'.LABEL;';
	execute dynsql1 into columnlist;
	-- 2. set up the crosstab query
	dynsql2 = 'select * from crosstab (
 ''select '||rowc||','||colc||','||cellc||' from '||tablename||' group by 1,2 order by 1,2'',
 ''select distinct '||colc||' from '||tablename||' order by 1''
 )
 as newtable (
 '||rowc||' varchar,'||columnlist||'
 );';
	return dynsql2;
end
$$
