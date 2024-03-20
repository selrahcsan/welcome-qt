#include "checktheme.h"

checkTheme::checkTheme() {}

QString checkTheme::getTheme(){
    QProcess process;
    process.start("plasma-apply-desktoptheme", QStringList() << "--list-themes");
    process.waitForFinished();

    QByteArray data = process.readAllStandardOutput();
    QString output(data);

    QStringList themes = output.split("\n", Qt::SkipEmptyParts);
    QStringList currentTheme = themes.filter("current", Qt::CaseInsensitive);

    QString themeName = currentTheme.first();

    if (!currentTheme.isEmpty())
    {
        if (themeName.contains("light", Qt::CaseInsensitive))
            return "light";
        else if (themeName.contains("dark", Qt::CaseInsensitive))
            return "dark";
        else if (themeName.contains("default", Qt::CaseInsensitive))
            return "default";
    }
    return "light";
}

void checkTheme::setTheme(std::string color, std::string mode){

    mode[0] = toupper(mode[0]);
    color[0] = toupper(color[0]);

    QString cor = QString::fromUtf8(color.c_str());
    QString modo = QString::fromUtf8(mode.c_str());

    QString fullName = cor + "-" + modo;

    QProcess desktopThemeProcess;
    desktopThemeProcess.start("plasma-apply-desktoptheme", QStringList() << fullName);
    desktopThemeProcess.waitForFinished();

    QProcess colorSchemeProcess;
    colorSchemeProcess.start("plasma-apply-colorscheme", QStringList() << fullName);
    colorSchemeProcess.waitForFinished();

    QProcess iconColorProcess;
    iconColorProcess.start("/usr/lib/x86_64-linux-gnu/libexec/plasma-changeicons", QStringList() << cor);
    iconColorProcess.waitForFinished();

    setColor();
}

QString checkTheme::getIcon(){
    QProcess process;
    process.start("plasma-apply-colorscheme", QStringList() << "-l");
    process.waitForFinished();

    QByteArray data = process.readAllStandardOutput();
    QString output(data);

    QStringList icons = output.split("\n", Qt::SkipEmptyParts);
    QStringList currentIcon = icons.filter("atual", Qt::CaseInsensitive);

    QString themeName = currentIcon.first();

    if (!currentIcon.isEmpty())
    {
        if (themeName.contains("orange", Qt::CaseInsensitive))
            return "orange";
        else if (themeName.contains("brown", Qt::CaseInsensitive))
            return "brown";
        else if (themeName.contains("cyan", Qt::CaseInsensitive))
            return "cyan";
        else if (themeName.contains("lavanda", Qt::CaseInsensitive))
            return "lavanda";
    }
    return "default";
}

void checkTheme::setColor(){
    QString color = getIcon();
    QString colorHex;
    if (color == "orange")
        colorHex = "'#f69310'";
    else if (color == "brown")
        colorHex = "'#aa4000'";
    else if (color == "cyan")
        colorHex = "'#00828c'";
    else if (color == "lavanda")
        colorHex = "'#6a58f'";

    QProcess highlightColor;
    highlightColor.start("plasma-apply-colorscheme", QStringList() << "accent-color" << colorHex );
    highlightColor.waitForFinished();

}
