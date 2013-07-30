current_dir=$(pwd)
script_dir=$(dirname $0)
if [ $script_dir = '.' ]; then
  script_dir="$current_dir"
fi

db_dir=$1
current_user=$2
server="/var/run/postgresql"
port="5434"

export PGPASSFILE="$script_dir/.pgpass"
echo "#hostname:port:database:username:password" >> "$PGPASSFILE"
echo "*:*:precheckarchivesdb:precheck:hotel" >> "$PGPASSFILE"
echo "*:*:precheckdb:precheck:hotel" >> "$PGPASSFILE"
sudo sort -u "$PGPASSFILE" > "$PGPASSFILE.new"
sudo mv "$PGPASSFILE.new" "$PGPASSFILE"
sudo chown "$current_user:$current_user" "$PGPASSFILE"
sudo chmod 600 "$PGPASSFILE"

sudo chown postgres:postgres "$db_dir/datas"

echo -n "CREATE ROLE precheck LOGIN SUPERUSER PASSWORD 'hotel';CREATE TABLESPACE precheckts OWNER precheck LOCATION '$db_dir/datas/';CREATE DATABASE precheckarchivesdb OWNER precheck TABLESPACE precheckts;CREATE DATABASE precheckdb OWNER precheck TABLESPACE precheckts;\\q" | sudo su --login postgres --command "psql -U postgres"
echo -n "CREATE EXTENSION IF NOT EXISTS postgres_fdw;CREATE SERVER archivesrv FOREIGN DATA WRAPPER postgres_fdw OPTIONS ( host '$server', port '$port', dbname 'precheckarchivesdb');CREATE USER MAPPING FOR precheck SERVER archivesrv OPTIONS ( user 'precheck', password 'hotel' );\\q" | psql -U precheck -d precheckdb -a

k=0
while [ $k -le 6 ] ; do
  echo "\n\n_______________________\n\nk=$k"

  echo "\n\n"
  for filename in $script_dir/$k-*Tous-pgSQL.sql; do
	echo "\n\n$filename\n"
	psql -U precheck -d precheckarchivesdb -f $filename -a
	psql -U precheck -d precheckdb -f $filename -a
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
