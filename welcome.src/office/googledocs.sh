#!/usr/bin/env bash
#
#
# WELCOME PARA O TIGER OS
#
# Desenvolvido por eltonff 31/10/2020
# Fork Charles Santana 27/07/2023
# Com a ferramenta BigBashView
# Tecnologias utilizadas: bash, html, css, javascript e <3

WEBAPP_TARGET="${HOME}/.local/share"

mkdir -p "${WEBAPP_TARGET}/bin"
mkdir -p "${WEBAPP_TARGET}/applications"

#GoogleDocs
cat > "${WEBAPP_TARGET}/bin/gdocs" <<EOF
#!/usr/bin/env sh

webapp-player "https://docs.google.com/document"
EOF

chmod +x "${WEBAPP_TARGET}/bin/gdocs"

echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Google Docs
Exec=webapp-player https://docs.google.com/document
Categories=Office;
Icon=/opt/welcome-tiger/Welcome.Imgs/WebApps/docs.png" > /tmp/gdocs.desktop

cp -f /tmp/gdocs.desktop "${WEBAPP_TARGET}/applications"
rm /tmp/gdocs.desktop

#GoogleSheets
cat > "${WEBAPP_TARGET}/bin/gsheets" <<EOF
#!/usr/bin/env sh


webapp-player "https://docs.google.com/spreadsheets"
EOF

chmod +x "${WEBAPP_TARGET}/bin/gsheets"

echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Google Sheets
Exec=webapp-player https://docs.google.com/spreadsheets
Categories=Office;
Icon=/opt/welcome-tiger/Welcome.Imgs/WebApps/sheets.png" > /tmp/gsheets.desktop

cp -f /tmp/gsheets.desktop "${WEBAPP_TARGET}/applications"
rm /tmp/gsheets.desktop

#GoogleSlides
cat > "${WEBAPP_TARGET}/bin/gslides" <<EOF
#!/usr/bin/env sh


webapp-player "https://docs.google.com/presentation"
EOF

chmod +x "${WEBAPP_TARGET}/bin/gslides"

echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Google Slides
Exec=webapp-player https://docs.google.com/presentation
Categories=Office;
Icon=/opt/welcome-tiger/Welcome.Imgs/WebApps/slides.png" > /tmp/gslides.desktop

cp -f /tmp/gslides.desktop "${WEBAPP_TARGET}/applications"
rm /tmp/gslides.desktop

yad --info --borders=32 --fixed --center   --text="O Google Docs foi instalado com sucesso!" --modal   --width=380 --button="Ok":0 --borders=32 --fixed --center   

exit
