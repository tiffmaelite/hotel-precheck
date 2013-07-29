#!/bin/sh
echo "\nL'application va maintenant être installée dans ce dossier.\n"
git clone --single-branch --branch master https://github.com/tiffmaelite/hotel-precheck.git ./files
if [ $? -eq 0 ]; then
  #chmod???
  sudo cp -R ./files/install ./install
  sudo cp -R ./files/src/Database ./src/Database
  sudo cp -R ./build/qt5.1.0/release ./build/qt5.1.0/release
  #sudo cp -R ./files/SimplHotel ./SimplHotel
  chdir install
  sudo ./installation
fi
