#!/usr/bin/env bash
#
#
# WELCOME PARA O TIGER OS
#
# Desenvolvido por eltonff 31/10/2020
# Com a ferramenta BigBashView
# Tecnologias utilizadas: bash, html, css, javascript e <3
# Script by Natanael.755

windowID="$(xwininfo -name "Bem-vindo TigerOS" | head -n2 | tail -n1 | awk '{print $4}')"

function instalarPacote(){
  cd /tmp
  export DEBIAN_FRONTEND="noninteractive"
  pkexec apt  install "$1" -y && {
    yad --info --modal --width=380 --button="Ok":0 --attach="$windowID" \
    --text="O $2 foi instalado com sucesso!"
  } || {
    yad --error --modal --width=380 --button="Ok":0 --attach="$windowID" \
    --text="Não foi possível concluir a instalação...\nPor favor, tente novamente!"
  }
}

instalarPacote "$1" "$2" | yad --progress --no-cancel --width=380 --button="Ok":0 --modal \
--attach="$windowID" --auto-close --pulsate \
--text="\nPor favor, aguarde...\n" --title="Instalando o $2..."
