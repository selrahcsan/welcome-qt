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

    QMessageBox msgBox;
    msgBox.setWindowTitle("Temas");
    msgBox.setText(themeName);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.exec();


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

    QMessageBox msgBox;
    msgBox.setWindowTitle("Icones");
    msgBox.setText(themeName);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.exec();

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
