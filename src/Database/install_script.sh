#!/bin/sh

echo "\n\n\n\nLe système de gestion de base de données étant en place, les bases de données de l'application vont maintenant être créées, initialisées et pré-remplies.\n"
echo "Installation pour l'utilisateur $2 réalisée par $SUDO_USER\n\n"
current_dir=$(pwd)
script_dir=$(dirname $0)

if [ $script_dir = '.' ]; then
  script_dir="$current_dir"
fi

case $1 in
"fbSQL")
  rm "$script_dir/firebird/PreCheckCreaFullError.log"
  rm "$script_dir/firebird/PreCheckCreaError.log"
  rm "$script_dir/firebird/PreCheckCrea.log"
  echo "Si la commande isql n'est pas définie, veuillez taper \"alias isql='isql-fb'\" puis relancer ce script."
  sh "$script_dir/firebird/install_script_fbSQL.sh" $script_dir 2>> "$script_dir/firebird/PreCheckCreaFullError.log" 1>> "$script_dir/firebird/PreCheckCrea.log"
  sed '/NOTICE:\s*CREATE TABLE /d' "$script_dir/firebird/PreCheckCreaFullError.log" >> "$script_dir/firebird/PreCheckCreaError.log"
;;
"pgSQL")
  rm "$script_dir/postgresql/PreCheckCreaFullError.log"
  rm "$script_dir/postgresql/PreCheckCreaError.log"
  rm "$script_dir/postgresql/PreCheckCrea.log"
  sh "$script_dir/postgresql/install_script_pgSQL.sh" $script_dir $2 2>> "$script_dir/postgresql/PreCheckCreaFullError.log" 1>> "$script_dir/postgresql/PreCheckCrea.log"
  sed '/NOTICE:\s*\d*\s*CREATE TABLE/d' "$script_dir/postgresql/PreCheckCreaFullError.log" >> "$script_dir/postgresql/PreCheckCreaError.log"
  sed '/pgSQL.sql : No such file or directory/d' "$script_dir/postgresql/PreCheckCreaError.log" >> "$script_dir/postgresql/PreCheckCreaError.log2"
  sudo mv "$script_dir/postgresql/PreCheckCreaError.log2" "$script_dir/postgresql/PreCheckCreaError.log"
  sed '/already exists, skipping/d' "$script_dir/postgresql/PreCheckCreaError.log" >> "$script_dir/postgresql/PreCheckCreaError.log2"
  sudo mv "$script_dir/postgresql/PreCheckCreaError.log2" "$script_dir/postgresql/PreCheckCreaError.log"
  sed 's/psql:/\n\npsql:/g' "$script_dir/postgresql/PreCheckCreaError.log" >> "$script_dir/postgresql/PreCheckCreaError.log2"
  sudo mv "$script_dir/postgresql/PreCheckCreaError.log2" "$script_dir/postgresql/PreCheckCreaError.log"

echo "\n\n\nVous pouvez désormais configurer pgAdmin ou un autre logiciel graphique de gestion de base de données avec les informations suivantes :\n\nUtilisateur : precheck\nMot de passe de l'utilisateur precheck : hotel"
echo "Détail des informations pour la base de données precheckdb";
echo "\\set\n" | psql -U precheck -d precheckdb
echo "Détail des informations pour la base de données precheckarchivesdb";
echo "\\set\n" | psql -U precheck -d precheckarchivesdb
;;
esac

echo "\nL'installation est maintenant terminée."
