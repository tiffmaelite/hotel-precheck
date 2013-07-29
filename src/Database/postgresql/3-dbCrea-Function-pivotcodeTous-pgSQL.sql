-- PL/pgSQL code to create pivot tables with automatic column names
-- Eric Minikel, CureFFI.org - 2013-03-19
-- Modified by Tiffany Grenier (2013-07-08) for taking SQL types in other database

-- prerequisite: install the tablefunc module before using crosstab
CREATE EXTENSION IF NOT EXISTS tablefunc;



-- sourcetablename: name of source table you want to pivot
-- rowc: the name of the column in "sourcetablename" you want to be the rows
-- colc: the name of the column in "tablename" you want to be the columns
-- cellc: an aggregate expressiON determining how the cell values will be created
-- celldatatype: the name of the column in "tablename" you want to be the desired data type for the cells
-- tablename: name of the table cONtaining columns names values and types
-- sourcecolc: the name of the column in "sourcetablename" matching to column "colc"
-- rowctype: the type of datas in column "rowc"

--CREATE OR REPLACE FUNCTION  pivotcode (sourcetablename VARCHAR, rowc VARCHAR, colc VARCHAR, cellc VARCHAR, celldatatype VARCHAR, tablename VARCHAR, sourcecolc VARCHAR, rowctype VARCHAR)
CREATE OR REPLACE FUNCTION genpivotcode (sourcetablename VARCHAR, rowc VARCHAR, colc VARCHAR, cellc VARCHAR, celldatatype VARCHAR, tablename VARCHAR, sourcecolc VARCHAR, rowctype VARCHAR, pivottable VARCHAR)
RETURNS VARCHAR
AS $$

DECLARE
  columns_sql VARCHAR;
  crosstab_sql VARCHAR;
  columnlist VARCHAR;
BEGIN
	-- 1. retrieve list of column names and types.

	--in case of a single content type
	--celldtype = 'VARCHAR';
	--columns_sql = 'SELECT string_agg(DISTINCT ''_''||'||colc||'||'' '||celldtype||''', '', '' ORDER BY ''_''||'||colc||'||'' '||celldtype||''') FROM '||sourcetablename||';';

	--in case content type is given in the same table as categories
	columns_sql = 'SELECT string_agg(''_''||'||colc||'||'' ''||'||celldatatype||'||'''', '', '') FROM (SELECT DISTINCT '||colc||', '||celldatatype||', '||tablename||'.id FROM '||tablename||' JOIN '||sourcetablename||' ON '||tablename||'.id = '||sourcetablename||'.'||sourcecolc||' ORDER BY '||tablename||'.id) AS source;';

	EXECUTE columns_sql INTO columnlist;
	--RAISE NOTICE 'columns_sql: %', columns_sql;

	-- 2. set up the crosstab query [crosstab(text source_sql, text category_sql)]

	-- The main limitation of the single-parameter form of crosstab is that it treats all values in a group alike, inserting each value into the first available column. If you want the value columns to correspond to specific categories of data, and some groups might not have data for some of the categories, that doesn't work well. The two-parameter form of crosstab handles this case by providing an explicit list of the categories corresponding to the output columns.
	-- The first parameter is a SQL statement that produces the source set of data and returns one row_name column, one category column, and one value column, as well as possible extra columns (which are expected to be the same for all rows with the same row_name value) between the first and the last two columns previously mentioned.
	-- The second parameter is a SQL statement that produces a duplicates-free non-empty set of datas

	--crosstab_sql = 'SELECT * INTO '||pivottable||' FROM crosstab (''SELECT '||rowc||', '||sourcecolc||', string_agg('||cellc||','''','''') FROM '||sourcetablename||' GROUP BY '||rowc||','||sourcecolc||' ORDER BY '||rowc||','||sourcecolc||''', ''SELECT DISTINCT '||sourcecolc||' FROM  '||sourcetablename||' ORDER BY '||sourcecolc||''') AS '||pivottable||' ('||rowc||' '||rowctype||', '||columnlist||');'; -- actual names and types of the output columns, since the crosstab function is declared to return setof record.

	crosstab_sql = 'CREATE TABLE '||pivottable||' AS (SELECT * FROM crosstab (''SELECT '||rowc||', '||sourcecolc||', string_agg('||cellc||','''','''') FROM '||sourcetablename||' GROUP BY '||rowc||','||sourcecolc||' ORDER BY '||rowc||','||sourcecolc||''', ''SELECT DISTINCT '||sourcecolc||' FROM  '||sourcetablename||' ORDER BY '||sourcecolc||''') AS '||pivottable||' ('||rowc||' '||rowctype||', '||columnlist||'));';

EXECUTE crosstab_sql;

	--RAISE NOTICE 'crosstab_sql: %', crosstab_sql;
	RETURN crosstab_sql;

END;
$$ LANGUAGE plpgsql VOLATILE;
