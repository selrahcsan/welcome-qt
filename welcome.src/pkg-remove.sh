#!/usr/bin/env bash
#
#
# WELCOME PARA O TIGER OS
#
# Desenvolvido por eltonff 31/10/2020
# Com a ferramenta BigBashView
# Tecnologias utilizadas: bash, html, css, javascript e <3
# Script by Natanael.755

PID="$(pidof $1)"
[ "$PID" ] && kill $(echo $PID)

windowID="$(xwininfo -name "Bem-vindo TigerOS" | head -n2 | tail -n1 | awk '{print $4}')"

[ "$(pidof zenity)" ] && zenity --warning --width=380 --modal --attach="$windowID" \
--text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit

function removerPacote(){
    export DEBIAN_FRONTEND="noninteractive"
    apt remove --purge "$1" -y && {
        apt-get autoremove --purge -y
        [ "$1" = "brave-browser" ] && rm -f /etc/apt/sources.list.d/brave*
        zenity --info --width=380 --attach="$windowID" --modal \
        --text="O $2 foi removido com sucesso!"
    } || {
        zenity --error --width=380 --attach="$windowID" --modal \
        --text="Não foi possível concluir a remoção...\nPor favor, tente novamente!"
  }
}

removerPacote "$1" "${2/-/ }" | zenity --progress --no-cancel --width=380 --modal \
--attach="$windowID" --auto-close --pulsate \
--text="\nPor favor, aguarde...\n" --title="Removendo o ${2/-/ }..."

exit
