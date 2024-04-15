
echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Google Documentos
Exec=webapp-player https://docs.google.com/document/u/0/
Categories=Office;
Icon=/usr/share/tiger-resources/docs.png" > /usr/share/applications/gdocs.desktop


echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Google Planilhas
Exec=webapp-player https://docs.google.com/spreadsheets/u/0/
Categories=Office;
Icon=/usr/share/tiger-resources/sheets.png" > /usr/share/applications/gsheets.desktop

echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Google Apresentações
Exec=webapp-player https://docs.google.com/presentation/u/0/
Categories=Office;
Icon=/usr/share/tiger-resources/slides.png" > /usr/share/applications/gslides.desktop

echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Google Formulários
Exec=webapp-player https://docs.google.com/forms/u/0/
Categories=Office;
Icon=/usr/share/tiger-resources/gforms.png" > /usr/share/applications/gforms.desktop

echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Google Keep
Exec=webapp-player https://keep.google.com/
Categories=Office;
Icon=/usr/share/tiger-resources/" > /usr/share/applications/gkeep.desktop

echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Google Agenda
Exec=webapp-player https://calendar.google.com/calendar/u/0/r?pli=1
Categories=Office;
Icon=/usr/share/tiger-resources/gAgenda.png" > /usr/share/applications/gagenda.desktop
