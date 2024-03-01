#!/usr/bin/env bash
#
#
# WELCOME PARA O TIGER OS
#
# Desenvolvido por eltonff 31/10/2020
# Com a ferramenta BigBashView
# Tecnologias utilizadas: bash, html, css, javascript e <3

 

WEBAPP_TARGET="${HOME}/.local/share"

mkdir -p "${WEBAPP_TARGET}/bin"
mkdir -p "${WEBAPP_TARGET}/applications"

#WebApp General
cat > "${WEBAPP_TARGET}/bin/$1" <<EOF
#!/usr/bin/env sh
#
# Amofi - App mode for Firefox
# Copyright (C) 2017-2019  SEPBIT
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
# dash version 0.5
#
# @author    Vitor Guia <contato@vitor.guia.nom.br>
# @Modified by Bruno Goncalves <www.biglinux.com.br>
# @copyright 2017-2019 SEPBIT
# @license   http://www.gnu.org/licenses GPL-3.0-or-later
# @see       https://notabug.org/sepbit/amofi Repository of Amofi
#
#
#if [ "\$(grep "toolkit.legacyUserProfileCustomizations.stylesheets" "\$HOME/.$1/prefs.js")" = "" ]; then
#    rm -R "\$HOME/.$1"
#    mkdir -p "\$HOME/.$1/chrome"
#    echo 'user_pref("media.eme.enabled", true);' >> "\$HOME/.$1/prefs.js"
#    echo 'user_pref("toolkit.legacyUserProfileCustomizations.stylesheets", true);' >> "\$HOME/.$1/prefs.js"
#fi
#
# Custom profile
#echo "#nav-bar{visibility: collapse;} #TabsToolbar{visibility: collapse;}" >> "\$HOME/.$1/chrome/userChrome.css"
#echo "user_pref(\"browser.tabs.warnOnClose\", false);" >> "\$HOME/.$1/user.js"
#sed -i 's|user_pref("browser.urlbar.placeholderName.*||g' "\$HOME/.$1/prefs.js"

#MOZ_DISABLE_GMP_SANDBOX=1 MOZ_DISABLE_CONTENT_SANDBOX=1 \
#firefox --class=$1 -profile "\$HOME/.$1" \
#-no-remote -new-instance "$5" &
#
#count=0
#while [ \$count -lt 100 ]; do
#    if [ "\$(xwininfo -root -children -all | grep -iE "Navigator.*$1")" != "" ]; then
#        /usr/bin/xseticon -id "\$(xwininfo -root -children -all | grep -iE "Navigator.*$1" | awk '{print \$1}')" /usr/share/pixmaps/$4.png
#        count=100
#    else
#        let count=count+1;
#    fi
#    sleep 0.5
#done
webapp-player "$5"
EOF

chmod +x "${WEBAPP_TARGET}/bin/$1"

echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=$2
Exec=webapp-player $5
Categories=$3;
Icon=/opt/welcome-tiger/Welcome.Imgs/WebApps/$4".png > /tmp/"$1".desktop

cp -f /tmp/"$1".desktop "${WEBAPP_TARGET}/applications"
rm /tmp/"$1".desktop

# yad --info --borders=32 --fixed --center   --text="O webapp ${2} foi instalado com sucesso!\n" --modal   --width=380 --button="Ok":0 --borders=32 --fixed --center  

exit
