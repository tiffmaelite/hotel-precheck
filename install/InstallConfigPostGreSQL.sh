#!/bin/sh
ver=$1
echo "Exécutez la commande suivante pour installer postgresql :
\t sudo apt-get install postgresql-$ver postgresql-client-$ver postgresql-contrib-$ver pgadmin3 pgagent barman
Exécutez la commande suivante pour définir le mot de passe de l'utilisateur postgresql par défaut (postgres)
\t sudo su postgres -c \"psql -d template1\"
Lorsque template1# s'affiche, tappez :
\t\t ALTER USER postgres WITH PASSWORD 'postgres';
puis
\t\t \\q
Exécutez les commandes suivantes pour modifier le mot de passe du compte utilisateur postgres :
\t sudo passwd -d postgres
\t sudo su postgres -c passwd
puis tappez postgres, appuyez sur ENTRÉE, de nouveau postgres et de nouveau la touche ENTRÉE
Tappez la commande :
\t sudo leafpad /etc/postgresql/$ver/main/postgresql.conf
puis, dans le fichier qui va s'ouvrir, modifiez comme suit les lignes suivantes :
\t\t #listen_addresses = 'localhost'
en
\t\t listen_addresses = '*'
et
\t\t #password_encryption = on
en
\t\t password_encryption = on
Exécutez ensuite la commandes suivantes pour initialiser le cluster de bases de données :
\t sudo /etc/init.d/postgresql restart
\t sudo su postgres -c \"/usr/lib/postgresql/$ver/bin/initdb -D /usr/local/pgsql/data\"
Si la commande précédente a échoué, exécutez les 5 commandes suivantes avant de continuer :
\t sudo mkdir /usr/local/pgsql
\t sudo mkdir /usr/local/pgsql/data
\t sudo chown -R postgres /usr/local/pgsql
\t sudo chgrp -R postgres /usr/local/pgsql
\t sudo su postgres -c \"/usr/lib/postgresql/$ver/bin/initdb -D /usr/local/pgsql/data\"
Lancez le serveur avec l'une des deux commandes suivantes :
\t sudo su postgres -c \"/usr/lib/postgresql/$ver/bin/postgres -D /usr/local/pgsql/data >/usr/local/pgsql/data/logfile 2>&1 &\"
\t sudo su postgres -c \"/usr/lib/postgresql/$ver/bin/pg_ctl -D /usr/local/pgsql/data -l /usr/local/pgsql/data/logfile start\"
Exécutez la commande :
\t sudo leafpad /etc/rc.local
puis ajoutez dans le fichier qui s'ouvre, juste avant la ligne contenant \"exit 0;\" la ligne suivante pour déclencher le lancement de la base de données avec le démarrage de l'ordinateur
\t\t sudo su postgres -c \"/usr/lib/postgresql/$ver/bin/pg_ctl start -l /usr/local/pgsql/data/logfile -D /usr/local/pgsql/data\""
