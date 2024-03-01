#!/usr/bin/env bash
#
#
# WELCOME PARA O TIGER OS
#
# Desenvolvido por eltonff 31/10/2020
# Fork Charles Santana 27/07/2023
# Com a ferramenta BigBashView
# Tecnologias utilizadas: bash, html, css, javascript e <3

   

  case $1 in
      libreoffice)
          [ "$(pidof yad)" ] && yad --warning --borders=32 --fixed --center     --width=380 --button="Ok":0 --modal \
          --text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY "$PWD"/office/libreoffice.sh
          exit
          ;;

      wps)
          [ "$(pidof yad)" ] &&  yad --warning --borders=32 --fixed --center     --width=380 --button="Ok":0 --modal \
          --text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY "$PWD"/office/wps.sh
          exit
          ;;

      onlyoffice)
          flatpak-install-gui --override-appname="OnlyOffice" org.onlyoffice.desktopeditors
          exit
          ;;

      brave)
          [ "$(pidof yad)" ] && yad --warning --borders=32 --fixed --center     --width=380 --button="Ok":0 --modal \
          --text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY "$PWD"/navegadores/brave.sh
          exit
          ;;

      chrome)
          [ "$(pidof yad)" ] && yad --warning --borders=32 --fixed --center     --width=380 --button="Ok":0 --modal \
          --text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY "$PWD"/navegadores/chrome.sh
          exit
          ;;

      opera)
          [ "$(pidof yad)" ] && yad --warning --borders=32 --fixed --center     --width=380 --button="Ok":0 --modal \
          --text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY "$PWD"/navegadores/opera.sh
          exit
          ;;

      edge)
          flatpak-install-gui --override-appname="Microsoft Edge" com.microsoft.Edge
          exit
          ;;

      firefox)
          [ "$(pidof yad)" ] && yad --warning --borders=32 --fixed --center     --width=380 --button="Ok":0 --modal \
          --text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY "$PWD"/navegadores/firefox.sh
          exit
          ;;

      tor)
          flatpak-install-gui --override-appname="Tor Browser" com.github.micahflee.torbrowser-launcher
          exit
          ;;

      update)
          io.elementary.appcenter --show-updates &
          exit
          ;;

      clamav)
          [ "$(pidof yad)" ] && yad --warning   --width=380 --button="Ok":0 --modal \
          --text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY "$PWD"/tarefasAdicionais/clamav.sh
          exit
          ;;

      msoffice)
          "$PWD"/office/msoffice.sh
          echo "Foi chamado" > /tmp/msoffice
          exit
          ;;
      office365)
        [ "$(pidof yad)" ] && yad --warning   --width=380 --button="Ok":0 --modal \
          --text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY "$PWD"/office/office365.sh
          exit
          ;;
      gdocs)
          "$PWD"/office/googledocs.sh
          echo "Foi chamado" > /tmp/gdocs
          exit
          ;;

      remmina)
          #[ "$(pidof yad)" ] && yad --warning   --width=380 --button="Ok":0 --modal \
          #--text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          #pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY "$PWD"/tarefasAdicionais/remmina.sh
          flatpak-install-gui --override-appname="Remmina" org.remmina.Remmina
          exit
          ;;

      codecs)
          [ "$(pidof yad)" ] && yad --warning   --width=380 --button="Ok":0 --modal \
          --text="Já existe outra instalação/remoção em andamento!\nAguarde a instalação/remoção concluir..." && exit
          "$PWD"/tarefasAdicionais/wrapper-codecs.sh
          exit
          ;;

      driver)
          driver-manager
          exit
          ;;

      gcontacts)
          "$PWD"/webapps.sh "$1" "Google Contacts" "Utility" "$1" "https://contacts.google.com" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Google Contacts foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      gcalendar)
          "$PWD"/webapps.sh "$1" "Google Calendar" "Utility" "$1" "https://calendar.google.com/calendar/u/0/r" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Google Calendar foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      gkeep)
          "$PWD"/webapps.sh "$1" "Google Keep" "Utility" "$1" "keep.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Google Keep foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      cvyou)
          "$PWD"/webapps.sh "$1" "CV2You" "Utility" "$1" "resume.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp CV2You foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      github)
          "$PWD"/webapps.sh "$1" "GitHub" "Development" "$1" "github.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp GitHub foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      gist)
          "$PWD"/webapps.sh "$1" "Gist" "Development" "$1" "gist.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Gist foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      glitch)
          "$PWD"/webapps.sh "$1" "Glitch" "Development" "$1" "glitch.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Glitch foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      codepen)
          "$PWD"/webapps.sh "$1" "CodePen" "Development" "$1" "pen.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp CodePen foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      diagrams)
          "$PWD"/webapps.sh "$1" "Diagrams" "Development" "$1" "diagrams.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Diagrams foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      gforms)
          "$PWD"/webapps.sh "$1" "Google Forms" "Office" "$1" "forms.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Google Forms foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      spark)
          "$PWD"/webapps.sh "$1" "Adobe Spark" "Graphics" "$1" "spark.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Adobe Spark foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      canva)
          "$PWD"/webapps.sh "$1" "Canva" "Graphics" "$1" "canva.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Canva foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      logomaker)
          "$PWD"/webapps.sh "$1" "Logo Maker" "Graphics" "$1" "logo.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Logo Maker foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      photoshop)
          "$PWD"/webapps.sh "$1" "Photoshop Online" "Graphics" "$1" "photoshop.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Photoshop Online foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      photopea)
          "$PWD"/webapps.sh "$1" "Photopea" "Graphics" "$1" "https://www.photopea.com/" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Photopea Online foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      gmeet)
          "$PWD"/webapps.sh "$1" "Google Meet" "Network" "$1" "meet.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Google Meet foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      medium)
          "$PWD"/webapps.sh "$1" "Medium" "Network" "$1" "story.new" && {
              yad --info --borders=32 --fixed --center   --text="O webapp Medium foi instalado com sucesso!" --modal   --width=380 --button="Ok":0
          } || {
              yad --error --borders=32 --fixed --center   --text="Não foi possível concluir a instalação do webapp!" --modal   --width=380 --button="Ok":0
          }
          exit
          ;;

      *) exit ;;
  esac
