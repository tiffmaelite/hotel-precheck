#!/bin/sh
echo "\nL'application va maintenant être installée dans ce dossier.\n"
git clone --single-branch --branch master https://github.com/tiffmaelite/hotel-precheck.git ./files
if [ $? -eq 0 ]; then
  #chmod???
  sudo cp -R ./files/install ./install
  sudo cp -R ./files/src/Database ./src/Database
  chdir install
  sudo ./installation_server
fi
