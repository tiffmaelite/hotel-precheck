db_dir=$1
current_user=$2

current_dir=$(pwd)
script_dir=$(dirname $0)
if [ $script_dir = '.' ]; then
  script_dir="$current_dir"
fi

export PGPASSFILE="$script_dir/.pgpass"
echo "#hostname:port:database:username:password" >> "$PGPASSFILE"
echo "*:*:precheckarchivesdb:precheck:hotel" >> "$PGPASSFILE"
sudo sort -u "$PGPASSFILE" > "$PGPASSFILE.new"
sudo mv "$PGPASSFILE.new" "$PGPASSFILE"
sudo chown "$current_user:$current_user" "$PGPASSFILE"
sudo chmod 600 "$PGPASSFILE"

sudo chown postgres:postgres "$1/datas"

echo -n "CREATE ROLE precheck LOGIN SUPERUSER PASSWORD 'hotel';CREATE TABLESPACE precheckts OWNER precheck LOCATION '$1/datas/';CREATE DATABASE precheckarchivesdb OWNER precheck TABLESPACE precheckts;\\q" | sudo su --login postgres --command "psql -U postgres"


k=0
while [ $k -le 6 ] ; do
  echo "\n\n_______________________\n\nk=$k"

  echo "\n\n"
  for filename in $script_dir/$k-*Tous-pgSQL.sql; do
	echo "\n\n$filename\n"
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


  k=`expr $k + 1`
done;
