#!/bin/sh
echo "L'application ainsi que ses bases de données et ses fichiers de configuration vont maintenant être désinstallés."

ver=9.3
script_dir=$(dirname $0)

chdir "../src/Database"
current_dir=$(pwd)
rm "$current_dir/postgresql/PreCheckCreaFullError.log"
rm "$current_dir/postgresql/PreCheckCreaError.log"
rm "$current_dir/postgresql/PreCheckCrea.log"
rm "$current_dir/firebirdsql/PreCheckCreaFullError.log"
rm "$current_dir/firebirdsql/PreCheckCreaError.log"
rm "$current_dir/firebirdsql/PreCheckCrea.log"
  
  
chdir $script_dir
sudo rm -R "/usr/local/pgsql$ver"
sudo apt-get remove -y postgresql-$ver postgresql-client-$ver postgresql-contrib-$ver pgadmin3 phppgadmin pgagent barman pgbouncer pgpool2
sudo apt-get autoremove -y
sudo apt-get autoclean
sudo apt-get install -fy

sudo sed -i"_$(date +"d_%m_%y_%H_%M_%S%P").bak" "s/\nsudo su postgres -c \"\/usr\/lib\/postgresql\/$ver\/bin\/pg_ctl start -l \/usr\/local\/pgsql$ver\/data\/logfile -D \/usr\/local\/pgsql$ver\/data\"/\n/g" "/etc/rc.local"
