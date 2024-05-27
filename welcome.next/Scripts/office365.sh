
echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Microsoft Office Word 356
Exec=webapp-player https://www.microsoft365.com/launch/word?auth=1
Categories=Office;
Icon=/usr/share/tiger-resources/word.png" > /usr/share/applications/msword-365.desktop


echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Microsoft Office Excel 356
Exec=webapp-player https://www.microsoft365.com/launch/excel?auth=1
Categories=Office;
Icon=/usr/share/tiger-resources/excel.png" > /usr/share/applications/msexcel-365.desktop

echo "#!/usr/bin/env xdg-open
[Desktop Entry]
Version=1.0
Terminal=false
Type=Application
Name=Microsoft Office PowerPoint 365
Exec=webapp-player https://www.microsoft365.com/launch/powerpoint?auth=1
Categories=Office;
Icon=/usr/share/tiger-resources/powerpoint.png" > /usr/share/applications/mspowerpoint-365.desktop
