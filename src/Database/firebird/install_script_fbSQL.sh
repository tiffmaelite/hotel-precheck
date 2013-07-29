current_dir=$(pwd)
script_dir=$(dirname $0)

  database_file="$1/datas/PreCheckDB.fbdb"
  ardatabase_file="$1/datas/PreCheckArchivesDB.fbdb"
  chmod 777 $database_file;
  chmod 777 $ardatabase_file;
  gsec -user SYSDBA -password masterkey -add precheck -pw hotel
  isql -i "dbCreat_fbSQL.sql" -e
  sudo sh /opt/firebird/bin/createAliasDB.sh precheck-hotel $database_file
  sudo sh /opt/firebird/bin/createAliasDB.sh precheck-archives-hotel $ardatabase_file

  for k in 0..4; do
	for filename in $1/$k_*_fbSQL.sql; do
	  isql -i $filename -e
	done;
  done;

  isql -i "dbInitScript_fbSQL.sql" -e
