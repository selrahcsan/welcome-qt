#!/usr/bin/env bash

function instalarPacote(){
  export DEBIAN_FRONTEND="noninteractive"

  apt update -y
  wget https://github.com/agam778/MS-365-Electron/releases/download/v1.1.0/MS-365-Electron-v1.1.0-linux-amd64.deb | yad --no-buttons --progress --width=400 --height=100  --borders=32 --fixed --center
  apt install ./MS-365-Electron-v1.1.0-linux-amd64.deb -y {
    yad --info --modal --no-cancel --width=400 --height=100 --borders=32 --fixed --center   --button="Ok":0 \
    --text="O Office 365 foi instalado com sucesso!"
  } || {
    yad --error --modal --width=400 --height=100  --borders=32 --fixed --center   --button="Ok":0 \
    --text="Não foi possível concluir a instalação...\nPor favor, tente novamente!"
  }
  rm MS-365-Electron-v1.1.0-linux-amd64.deb
}

instalarPacote | yad --no-buttons --progress --width=400 --height=100  --borders=32 --fixed --center    \
  --auto-close --pulsate --progress-text= \
--text="\nPor favor, aguarde...\n" --title="Instalando o office 365..."

exit
