#!/usr/bin/env bash
#
#
# WELCOME PARA O TIGER OS
#
# Desenvolvido por eltonff 31/10/2020
# Fork Charles Santana 27/07/2023
# Com a ferramenta BigBashView
# Tecnologias utilizadas: bash, html, css, javascript e <3

 

function instalarPacote(){
  export DEBIAN_FRONTEND="noninteractive"
  apt update -y
  apt install remmina -y && {
    yad --info --modal  --borders=32 --fixed --center   --width=350   --button="Ok":0 \
    --text="O Remmina foi instalado com sucesso!"
  } || {
    yad --error --modal  --borders=32 --fixed --center   --width=350   --button="Ok":0 \
    --text="Não foi possível concluir a remoção...\nPor favor, tente novamente!"
  }
}

instalarPacote | yad --progress  --borders=32 --fixed --center   --no-buttons --no-cancel --width=350 --modal \
  --auto-close --pulsate  --progress-text= \
--text="\nPor favor, aguarde...\n" --title="Instalando o Remmina..."

exit
