#!/bin/sh


#gsec -user SYSDBA -password masterkey -add precheck -pw hotel;
#alias isql='isql-fb';

for filename in $PWD/0_*.sql
do
		isql -i $filename -e  2> "PreCheckCreaError.log" 1>"PreCheckCrea.log";
done;

sudo sh /opt/firebird/bin/createAliasDB.sh precheck-hotel $PWD/PreCheckDB.fdb;

for filename in $PWD/1_*.sql
do
		isql -i $filename -e  2>> "PreCheckCreaError.log" 1>>"PreCheckCrea.log";
done;

for filename in $PWD/2_*.sql
do
		isql -i $filename -e  2>> "PreCheckCreaError.log" 1>>"PreCheckCrea.log";
done;

for filename in $PWD/3_*.sql
do
		isql -i $filename -e  2>> "PreCheckCreaError.log" 1>>"PreCheckCrea.log";
done;

for filename in $PWD/4_*.sql
do
		isql -i $filename -e  2>> "PreCheckCreaError.log" 1>>"PreCheckCrea.log";
done;

isql -i "dbInitScript.sql" -e  2>> "PreCheckCreaError.log" 1>>"PreCheckCrea.log";


chmod 777 $PWD/PreCheckDB.fdb;
