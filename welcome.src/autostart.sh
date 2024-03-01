#!/usr/bin/env bash
#
#
# WELCOME PARA O TIGER OS
#
# Desenvolvido por eltonff 31/10/2020
# Com a ferramenta BigBashView
# Tecnologias utilizadas: bash, html, css, javascript e <3

mkdir -p ~/.config/autostart

if [ -e ~/.config/autostart/Tiger-Preview.desktop ];then
    rm ~/.config/autostart/Tiger-Preview.desktop
else
    cp /usr/share/applications/Tiger-Preview.desktop ~/.config/autostart/
#     echo "[Desktop Entry]
# Hidden=true" > ~/.config/autostart/Tiger-Preview.desktop
fi
exit