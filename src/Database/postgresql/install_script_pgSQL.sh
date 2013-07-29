current_dir=$(pwd)
script_dir=$(dirname $0)

export PGPASSFILE="$script_dir/.pgpass"
echo "#hostname:port:database:username:password" >> "$PGPASSFILE"
echo "*:*:precheckdb:precheck:hotel" >> "$PGPASSFILE"
echo "*:*:precheckarchivesdb:precheck:hotel" >> "$PGPASSFILE"
sudo sort -u "$PGPASSFILE" > "$PGPASSFILE.new"
sudo mv "$PGPASSFILE.new" "$PGPASSFILE"
sudo chown "$2:$2" "$PGPASSFILE"
sudo chmod 600 "$PGPASSFILE"
echo "$PGPASSFILE"

sudo chown postgres:postgres "$1/datas"

echo -n "DROP DATABASE precheckdb;DROP DATABASE precheckarchivesdb;DROP TABLESPACE precheckts;DROP USER precheck;CREATE ROLE precheck LOGIN SUPERUSER PASSWORD 'hotel';CREATE TABLESPACE precheckts OWNER precheck LOCATION '$1/datas/';CREATE DATABASE precheckdb OWNER precheck TABLESPACE precheckts;CREATE DATABASE precheckarchivesdb OWNER precheck TABLESPACE precheckts;\\q" | sudo su --login postgres --command "psql -U postgres"


k=0
while [ $k -le 6 ] ; do
  echo "\n\n_______________________\n\nk=$k"

  echo "\n\n"
  for filename in $script_dir/$k-*Tous-pgSQL.sql; do
	echo "\n\n$filename\n"
	psql -U precheck -d precheckdb -f $filename -a
	psql -U precheck -d precheckarchivesdb -f $filename -a
  done;


  #aroutput="$script_dir/$k-archives-pgSQL.sql"
  #rm $aroutput
  echo "\n\n"
  for filename in $script_dir/$k-*Archives-pgSQL.sql; do
	echo "\n\n$filename\n"
	psql -U precheck -d precheckarchivesdb -f $filename -a
	#cat $filename >> $aroutput
  done;
  #psql -U precheck -d precheckarchivesdb -f $aroutput -a


  #output="$script_dir/$k-main-pgSQL.sql"
  #rm $output
  echo "\n\n"
  for filename in $script_dir/$k-*Main-pgSQL.sql; do
	echo "\n\n$filename\n"
	psql -U precheck -d precheckdb -f $filename -a
	#cat $filename >> $output
  done;
  #psql -U precheck -d precheckdb -f $output -a

  k=`expr $k + 1`
done;
