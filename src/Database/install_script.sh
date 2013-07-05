#!/bin/sh

command_name = "sh";
database_file = "";

case $1 in
"fbSQL")
  command_name = "isql -i ";
  database_file = "PreCheckDB.fbdb";
  gsec -user SYSDBA -password masterkey -add precheck -pw hotel;
  echo "Si la commande isql n'est pas définie, veuillez taper \"alias isql='isql-fb'\" puis relancer ce script.";
;;
"pgSQL")
  command_name = "psql -f ";
  database_file = "PreCheckDB.pgdb";
  echo "hotel\n" | su --login postgres --command "createuser --createdb --pwprompt --no-superuser --no-createrole precheck"
;;
esac

for filename in $PWD/0_*_$1.sql; do
  $command_name $filename -e  2> "PreCheckCreaError.log" 1>"PreCheckCrea.log";
done;

if [ $i -eq "fbSQL" ]; then
  sudo sh /opt/firebird/bin/createAliasDB.sh precheck-hotel $PWD/PreCheckDB.fdb;
fi

for k in 1..4; do
  for filename in $PWD/$k_*_1.sql; do
	$command_name $filename -e  2>> "PreCheckCreaError.log" 1>>"PreCheckCrea.log";
  done;
done;

$command_name "dbInitScript_$1.sql" -e  2>> "PreCheckCreaError.log" 1>>"PreCheckCrea.log";

chmod 777 $PWD/$database_file;
