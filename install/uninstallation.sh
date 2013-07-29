#!/bin/sh
echo "L'application ainsi que ses fichiers de cnfiguration vont maintenant être désinstallés."

ver=9.3
sudo rm -R "/usr/local/pgsql$ver"
sudo apt-get remove -y postgresql-$ver postgresql-client-$ver postgresql-contrib-$ver pgadmin3 phppgadmin pgagent barman pgbouncer pgpool2
sudo apt-get autoremove -y
sudo apt-get autoclean
sudo apt-get install -fy

sudo sed -i"_$(date +"d_%m_%y_%H_%M_%S%P").bak" "s/\nsudo su postgres -c \"\/usr\/lib\/postgresql\/$ver\/bin\/pg_ctl start -l \/usr\/local\/pgsql$ver\/data\/logfile -D \/usr\/local\/pgsql$ver\/data\"/\n/g" "/etc/rc.local"
