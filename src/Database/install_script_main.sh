#!/bin/sh
current_user=$2
dbtype=$1

current_dir=$(pwd)
script_dir=$(dirname $0)
if [ $script_dir = '.' ]; then
  script_dir="$current_dir"
fi

echo "\n\n\n\nLe système de gestion de base de données étant en place, les bases de données de l'application vont maintenant être créées, initialisées et pré-remplies.\n"
echo "Installation pour l'utilisateur $current_user\n\n"

echo "Veuillez entrer l'adresse IP du serveur sur lequel les bases de données serveur de l'application ont été créées:"
read serverip
echo "Veuillez entrer le chemin de l'hôte du cluster postgresql de ce serveur:"
read serverhost
echo "Veuillez entrer le port du cluster postgresql de ce serveur:"
read serverport

server="$serverip$serverhost"

case $dbtype in
"fbSQL")
  echo "Si la commande isql n'est pas définie, veuillez taper \"alias isql='isql-fb'\" puis relancer ce script."
  sh "$script_dir/firebird/install_script_main_fbSQL.sh" $script_dir $server 2>> "$script_dir/firebird/PreCheckCreaFullError.log" 1>> "$script_dir/firebird/PreCheckCrea.log"
  sed '/NOTICE:\s*CREATE TABLE /d' "$script_dir/firebird/PreCheckCreaFullError.log" >> "$script_dir/firebird/PreCheckCreaError.log"
;;
"pgSQL")
  sh "$script_dir/postgresql/install_script_main_pgSQL.sh" $script_dir $current_user $server $serverport 2>> "$script_dir/postgresql/PreCheckCreaFullError.log" 1>> "$script_dir/postgresql/PreCheckCrea.log"
  sed '/NOTICE:\s*\d*\s*CREATE TABLE/d' "$script_dir/postgresql/PreCheckCreaFullError.log" >> "$script_dir/postgresql/PreCheckCreaError.log"
  sed '/pgSQL.sql : No such file or directory/d' "$script_dir/postgresql/PreCheckCreaError.log" >> "$script_dir/postgresql/PreCheckCreaError.log2"
  sudo mv "$script_dir/postgresql/PreCheckCreaError.log2" "$script_dir/postgresql/PreCheckCreaError.log"
  sed '/already exists, skipping/d' "$script_dir/postgresql/PreCheckCreaError.log" >> "$script_dir/postgresql/PreCheckCreaError.log2"
  sudo mv "$script_dir/postgresql/PreCheckCreaError.log2" "$script_dir/postgresql/PreCheckCreaError.log"
  sed 's/psql:/\n\npsql:/g' "$script_dir/postgresql/PreCheckCreaError.log" >> "$script_dir/postgresql/PreCheckCreaError.log2"
  sudo mv "$script_dir/postgresql/PreCheckCreaError.log2" "$script_dir/postgresql/PreCheckCreaError.log"

echo "\n\n\nVous pouvez désormais configurer pgAdmin ou un autre logiciel graphique de gestion de base de données avec les informations suivantes :\n\nUtilisateur : precheck\nMot de passe de l'utilisateur precheck : hotel"
echo "Détail des informations pour la base de données precheckdb:";
echo "\\set\n" | psql -U precheck -d precheckdb
;;
esac

echo "\nL'installation est maintenant terminée."
