#!/bin/sh
ver=9.3
echo "\nLe système va maintenant procéder à l'installation et à la configuration du système de gestion de la base de données\n\n\n\n"
echo "Installation pour l'utilisateur $SUDO_USER\n"

count=`ls -1 apt.postgresql.org.sh* 2>/dev/null | wc -l`
if [ $count -eq 0 ] ;then
  wget --quiet http://anonscm.debian.org/loggerhead/pkg-postgresql/postgresql-common/trunk/download/head:/apt.postgresql.org.s-20130224224205-px3qyst90b3xp8zj-1/apt.postgresql.org.sh
fi

echo -n "\n" | sudo sh apt.postgresql.org.sh

#if [ $? -ne 0 ]; then
  #wget --quiet http://anonscm.debian.org/loggerhead/pkg-postgresql/postgresql-common/trunk/download/head:/apt.postgresql.org.s-20130224224205-px3qyst90b3xp8zj-1/apt.postgresql.org.sh
  #echo -n "\n" | sudo sh apt.postgresql.org.sh
#fi

sudo apt-get install -y postgresql-$ver postgresql-client-$ver postgresql-contrib-$ver pgadmin3 phppgadmin pgagent barman pgbouncer pgpool2
sudo apt-get install -fy

echo -n "ALTER USER postgres WITH PASSWORD 'postgres';\n\\q" | sudo su postgres -c "psql -d template1"
sudo passwd -d postgres
echo -n "postgres\npostgres\n" | sudo su postgres -c passwd

PATH="/usr/lib/postgresql/$ver/bin:$PATH"
export PATH

sudo cp "/etc/postgresql/$ver/main/postgresql.conf" "/etc/postgresql/$ver/main/postgresql.conf.bak"
sudo sed -i"_$(date +"d_%m_%y_%H_%M_%S%P").bak" "s/#listen_addresses = 'localhost'/listen_addresses = '*'/g" "/etc/postgresql/$ver/main/postgresql.conf"
sudo sed -i"_$(date +"d_%m_%y_%H_%M_%S%P").bak" "s/#password_encryption = on/password_encryption = on/g" "/etc/postgresql/$ver/main/postgresql.conf"
sudo sed -i"_$(date +"d_%m_%y_%H_%M_%S%P").bak" "s/local\s+all\s+all\s+peer/local\t all\t all\t md5/g" "/etc/postgresql/$ver/main/postgresql.conf"

#sudo locale-gen fr_FR
#sudo locale-gen fr_CH
sudo locale-gen fr_FR.utf8
sudo locale-gen fr_FR@euro
sudo locale-gen fr_CH.utf8
#sudo locale-gen de_DE
#sudo locale-gen de_CH
sudo locale-gen de_DE.utf8
sudo locale-gen de_DE@euro
sudo locale-gen de_CH.utf8
sudo update-locale

sudo /etc/init.d/postgresql restart

sudo su postgres -c "/usr/lib/postgresql/$ver/bin/initdb -D /usr/local/pgsql$ver/data --locale=fr_FR.utf-8" # --lc-time=fr_CH.utf-8 --lc-monetary=fr_CH.utf-8"
if [ $? -ne 0 ]; then
  echo "Directory /usr/local/pgsql$ver/data will be manually created."
  sudo mkdir "/usr/local/pgsql$ver"
  sudo mkdir "/usr/local/pgsql$ver/data"
  sudo chown -R postgres "/usr/local/pgsql$ver"
  sudo chgrp -R postgres "/usr/local/pgsql$ver"
sudo su postgres -c "/usr/lib/postgresql/$ver/bin/initdb -D /usr/local/pgsql$ver/data --locale=fr_FR.utf-8" # --lc-time=fr_CH.utf-8 --lc-monetary=fr_CH.utf-8"
fi

sudo su postgres -c "/usr/lib/postgresql/$ver/bin/pg_ctl -l /usr/local/pgsql$ver/data/logfile start -D /usr/local/pgsql$ver/data"

sudo cp /etc/rc.local /etc/rc.local.bak
sudo sed -i"_$(date +"&#37;d_%m_%y_%H_%M_%S%P").bak" "s/\nexit 0/\nsudo su postgres -c \"\/usr\/lib\/postgresql\/$ver\/bin\/pg_ctl start -l \/usr\/local\/pgsql$ver\/data\/logfile -D \/usr\/local\/pgsql$ver\/data\"\n\nexit 0/g" "/etc/rc.local"

sudo uniq "/etc/rc.local" > "$pwd/rc.local2"
sudo mv "$pwd/rc.local2" "/etc/rc.local"

chdir ../src/Database/
sudo sh install_script.sh pgSQL $SUDO_USER
