#include "Welcome.h"
#include "ui_Welcome.h"
#include <QProcess>
#include <QFile>
#include <QStandardPaths>

Welcome::Welcome(QWidget *parent): QMainWindow(parent), ui(new Ui::Welcome){
    ui->setupUi(this);

    // Give Categories a better look and feel

    for(int i = 0; i < ui->categories->count(); ++i){
        QListWidgetItem* item = ui->categories->item(i);
        if (item->text()=="WebApps") {
            item->setHidden(true);
            continue;
        }
        item->setSizeHint(QSize(48,48));
        ui->categories->setMinimumHeight(ui->categories->minimumHeight()+48);
    }

    // Connect Light/Dork Themes
    connect(ui->BreezeDark,SIGNAL(clicked()),this,SLOT(activateTheme()),Qt::UniqueConnection);
    connect(ui->BreezeLight,SIGNAL(clicked()),this,SLOT(activateTheme()),Qt::UniqueConnection);

    // Connect colors
    for (int i = 0; i < ui->colorContainer->layout()->count(); ++i) {
        QWidget *widget = ui->colorContainer->layout()->itemAt(i)->widget();
        if (QPushButton *button = qobject_cast<QPushButton*>(widget)) {
            connect(button,SIGNAL(clicked()),this,SLOT(activateAccentColor()),Qt::UniqueConnection);
        }
    }

    // Connect tasks
    for (int i = 0; i < ui->taskContainer->layout()->count(); ++i) {
        QWidget *widget = ui->taskContainer->layout()->itemAt(i)->widget();
        if (QPushButton *button = qobject_cast<QPushButton*>(widget)) {
            connect(button,SIGNAL(clicked()),this,SLOT(startTask()),Qt::UniqueConnection);
        }
    }

    checkMode();
    checkColors();

    fillOfficePage();
    fillBrowserPage();

    ui->categories->setCurrentRow(0);
}

Welcome::~Welcome(){
    delete ui;
}

void Welcome::checkMode(){
    QProcess process;
    process.start("plasma-apply-colorscheme", QStringList() << "--list-schemes");
    process.waitForFinished(-1);

    QByteArray data = process.readAllStandardOutput();
    QString output(data);

    QStringList themes = output.split("\n", Qt::SkipEmptyParts);
    QString currentTheme = themes.filter(QRegularExpression("^\\*"))[0];

    setProperty("themeMode","Light");

    if (currentTheme.contains("Dark")) {
      ui->BreezeDark->setChecked(true);
      setStyleSheet("* {color:#f6fcfc;background-color:#2a2e32}");
      setProperty("themeMode","Dark");
      return;
    }

    setStyleSheet("* {color:#292629;background-color:#eff0f1}"
                  "#card {border: 1px solid #c4c5c6; background: #FFFFFF}");
}

void Welcome::checkColors(){
    QProcess process;
    process.start("kreadconfig5", QStringList() << "--file"
                                                << (QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)+"/kdeglobals")
                                                << "--group"
                                                << "General"
                                                << "--key"
                                                << "AccentColor");
    process.waitForFinished(-1);

    QByteArray data = process.readAll();
    QString currentTheme = QString(data).remove("\n");

    setProperty("color","Orange");

    for (int i = 0; i < ui->colorContainer->layout()->count(); ++i) {
        QWidget *widget = ui->colorContainer->layout()->itemAt(i)->widget();
        if (QPushButton *button = qobject_cast<QPushButton*>(widget)) {
           if (button->property("decimal").toString() == currentTheme) {
               QString hex = button->property("hexadecimal").toString();

               ui->categories->setStyleSheet("QListView::item:hover{background-color: "+hex+"}"+
                                             "QListView::item:selected{background-color: "+hex+"}");

               button->setChecked(true);

               setProperty("color",button->property("name").toString());
               break;
           }
        }
    }
}

void Welcome::on_categories_currentRowChanged(int currentRow){
    ui->pages->setCurrentIndex(currentRow);
}

void Welcome::startTask(){
    QProcess process;
    process.start(QObject::sender()->property("executable").toString(),
                  QObject::sender()->property("arguments").toStringList());
    process.waitForFinished();
}

void Welcome::activateTheme(){
    QProcess colorSchemeProcess;
    colorSchemeProcess.start("plasma-apply-colorscheme", QStringList() << QObject::sender()->objectName());
    colorSchemeProcess.waitForFinished();

    // Why 2 times?
    colorSchemeProcess.start("plasma-apply-colorscheme", QStringList() << QObject::sender()->objectName());
    colorSchemeProcess.waitForFinished();

    setProperty("themeMode","Light");

    if (QObject::sender()->objectName()=="BreezeDark") {
        setStyleSheet("* {color:#f6fcfc;background-color:#2a2e32}");
        setProperty("themeMode","Dark");
        return;
    }
    setStyleSheet("* {color:#292629;background-color:#eff0f1}");

    setPlasmaTheme();
}

void Welcome::activateAccentColor(){
    QString hex = QObject::sender()->property("hexadecimal").toString();

    QProcess highlightColor;
    highlightColor.start("plasma-apply-colorscheme", QStringList() << "--accent-color" << hex );
    highlightColor.waitForFinished();

    QProcess icon;
    icon.start("/usr/lib/x86_64-linux-gnu/libexec/plasma-changeicons",
               QStringList() << QObject::sender()->property("name").toString());
    icon.waitForFinished();

    setProperty("color",QObject::sender()->property("name").toString());

    ui->categories->setStyleSheet("QListView::item:hover{background-color: "+hex+"}"+
                                  "QListView::item:selected{background-color: "+hex+"}");

    setPlasmaTheme();
}

void Welcome::setPlasmaTheme(){
    QProcess desktopThemeProcess;
    desktopThemeProcess.start("plasma-apply-desktoptheme", QStringList() <<
                              QString(property("color").toString()+"-"+property("themeMode").toString()));
    desktopThemeProcess.waitForFinished();

    // Force aurorae as theme engine
    QProcess aroraeProcess;
    aroraeProcess.start("kwriteconfig5",
                      QStringList() << (QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)+"/kwinrc")
                                    << "--group"
                                    << "org.kde.kdecoration2"
                                    << "--key"
                                    << "library"
                                    << "org.kde.kwin.aurorae");
    aroraeProcess.waitForFinished(-1);

    // Force aurorae as theme engine
    QProcess aroraeThemeProcess;
    aroraeThemeProcess.start("kwriteconfig5",
                      QStringList() << (QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)+"/kwinrc")
                                    << "--group"
                                    << "org.kde.kdecoration2"
                                    << "--key"
                                    << "theme"
                                    << QString(property("color").toString()+"-"+property("themeMode").toString()));
    aroraeThemeProcess.waitForFinished(-1);

    // Force kwin reload
    QProcess kwinProcess;
    kwinProcess.start("qdbus",
                      QStringList() << "org.kde.KWin"
                                    << "/Kwin");
    kwinProcess.waitForFinished(-1);

}

QWidget*Welcome::createButton(QString name, QString icon_, QString checkInstall, QString install, QString remove){
    QPushButton*action = new QPushButton(this);
    action->setText("Instalar");
    action->setProperty("install",install);
    action->setProperty("remove",remove);
    action->setProperty("checkInstall",checkInstall);

    if (checkInstall.startsWith("/")) {
        QFile f(checkInstall);
        if (f.exists()) action->setText("Remover");
    } else {
        std::string comando = checkInstall.toStdString();
        int result = system(comando.c_str());
        if (WEXITSTATUS(result) == 0) action->setText("Remover");
    }

    QWidget*card = new QWidget(this);
    card->setMaximumSize(200,240);
    card->setMinimumSize(card->maximumSize());
    card->setLayout(new QVBoxLayout);
    card->setObjectName("card");

    QPushButton*icon = new QPushButton;
    icon->setIconSize(QSize(140,140));
    icon->setIcon(QIcon(icon_));
    icon->setFlat(true);
    icon->setAttribute(Qt::WA_TransparentForMouseEvents,true);

    QLabel*label = new QLabel(name);
    label->setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));
    label->setAttribute(Qt::WA_TransparentForMouseEvents,true);
    label->setStyleSheet("background-color: transparent");
    label->setAlignment(Qt::AlignHCenter);

    card->layout()->addWidget(icon);
    card->layout()->addWidget(label);
    card->layout()->addWidget(action);

    connect(action,SIGNAL(clicked()),this,SLOT(installApp()),Qt::UniqueConnection);

    return card;
}

void Welcome::fillOfficePage(){
    ui->officeContainer->addWidget(
                createButton(
                    "LibreOffice",
                    ":/Imgs/Office/Imgs/Office/g735.png",
                    "flatpak info org.libreoffice.LibreOffice",
                    "flatpak-install-gui --override-appname=\"LibreOffice\" org.libreoffice.LibreOffice",
                    "flatpak-install-gui --override-appname=\"LibreOffice\" --remove org.libreoffice.LibreOffice"),
      0,0);

    ui->officeContainer->addWidget(
                createButton(
                    "WPS Office",
                    ":/Imgs/Office/Imgs/Office/g30.png",
                    "flatpak info com.wps.Office",
                    "flatpak-install-gui --override-appname=\"WPS Office\" com.wps.Office",
                    "flatpak-install-gui --override-appname=\"WPS Office\" --remove com.wps.Office"),
      0,1);

    ui->officeContainer->addWidget(
                createButton(
                    "Google Docs",
                    ":/Imgs/Office/Imgs/Office/g42.png",
                    "/usr/share/applications/gdocs.desktop",
                    "://Scripts/googledocs.sh",
                    (
                        "rm /usr/share/applications/gdocs.desktop"
                        " /usr/share/applications/gsheets.desktop"
                        " /usr/share/applications/gslides.desktop"
                        " /usr/share/applications/gforms.desktop"
                        " /usr/share/applications/gkeep.desktop"
                        " /usr/share/applications/gagenda.desktop"
                    )),
      0,2);

    ui->officeContainer->addWidget(
                createButton(
                    "Office 365",
                    ":/Imgs/Office/Imgs/Office/g825.png",
                    "/usr/share/applications/msword-365.desktop",
                    "://Scripts/office365.sh",
                    (
                        "rm /usr/share/applications/msword-365.desktop"
                        " /usr/share/applications/msexcel-365.desktop"
                        " /usr/share/applications/mspowerpoint-365.desktop"
                    )),
      1,0);
}

void Welcome::fillBrowserPage(){
    ui->browserContainer->addWidget(
                createButton(
                    "Google Chrome",
                    ":/Imgs/Browsers/Imgs/Browsers/chrome.png",
                    "which google-chrome-stable",
                    (
                     "appname=\"Google Chrome\";\n"
                     "package=google-chrome-stable;\n"
                     "repository_apt_key_url=\"https://dl.google.com/linux/linux_signing_key.pub\";\n"
                     "repository_apt_key_file=\"google-chrome.gpg\";\n"
                     "repository_url=\"deb [signed-by=/etc/trusted_repository_keys/google-chrome.gpg arch=amd64] "
                     "http://dl.google.com/linux/chrome/deb/ stable main\";\n"
                    ),
                    "qapt-batch --uninstall google-chrome-stable"),
      0,0);

    ui->browserContainer->addWidget(
                createButton(
                    "Microsoft Edge",
                    ":/Imgs/Browsers/Imgs/Browsers/edge.png",
                    "flatpak info com.microsoft.Edge",
                    "flatpak-install-gui --override-appname=\"Microsoft Edge\" com.microsoft.Edge",
                    "flatpak-install-gui --override-appname=\"Microsoft Edge\" --remove com.microsoft.Edge"),
      0,1);

    ui->browserContainer->addWidget(
                createButton(
                    "Brave",
                    ":/Imgs/Browsers/Imgs/Browsers/brave.png",
                    "which brave-browser",
                    (
                     "appname=\"Brave\";\n"
                     "package=brave-browser;\n"
                     "repository_apt_key_url=\"https://brave-browser-apt-release.s3.brave.com/brave-browser-archive-keyring.gpg\";\n"
                     "repository_apt_key_file=\"brave.gpg\";\n"
                     "repository_url=\"deb [signed-by=/etc/trusted_repository_keys/brave.gpg arch=amd64] "
                     "https://brave-browser-apt-release.s3.brave.com/ stable main\";\n"
                    ),
                    "qapt-batch --uninstall brave-browser"),
      0,2);

    ui->browserContainer->addWidget(
                createButton(
                    "Opera",
                    ":/Imgs/Browsers/Imgs/Browsers/opera.png",
                    "which opera-stable",
                    (
                     "appname=\"Opera\";\n"
                     "package=opera-stable;\n"
                     "repository_apt_key_url=\"https://deb.opera.com/archive.key\";\n"
                     "repository_apt_key_file=\"opera.gpg\";\n"
                     "repository_url=\"deb [signed-by=/etc/trusted_repository_keys/opera.gpg arch=amd64] "
                     "https://deb.opera.com/opera-stable/ stable non-free\";\n"
                    ),
                    "qapt-batch --uninstall opera-stable"),
      1,0);

    ui->browserContainer->addWidget(
                createButton(
                    "Tor",
                    ":/Imgs/Browsers/Imgs/Browsers/tor.png",
                    "flatpak info com.github.micahflee.torbrowser-launcher",
                    "flatpak-install-gui --override-appname=\"Tor Browser\" com.github.micahflee.torbrowser-launcher",
                    "flatpak-install-gui --override-appname=\"Tor Browser\" --remove com.github.micahflee.torbrowser-launcher"),
      1,1);
}


void Welcome::installApp(){
    hide();

    QFile installer("://Scripts/debian-package.sh");
    installer.open(QIODevice::ReadOnly);

    QString script = QObject::sender()->property("install").toString()+QString(installer.readAll());

    if (QObject::sender()->property("install").toString().startsWith("flatpak-install-gui")) {
        script = QObject::sender()->property("install").toString();
    }

    if (QObject::sender()->property("install").toString().startsWith("://")) {
        QFile customInstaller(QObject::sender()->property("install").toString());
        customInstaller.open(QIODevice::ReadOnly);

        script = customInstaller.readAll();
    }

    if (QObject::sender()->property("text").toString() == "Remover") {
        script = QObject::sender()->property("remove").toString();
        qDebug() <<script;
    }

    QProcess process;
    process.start("pkexec", QStringList()
                                                << "env"
                                                << QString("DISPLAY="+QString(getenv("DISPLAY")))
                                                << QString("XAUTHORITY="+QString(getenv("XAUTHORITY")))
                                                << QString("XDG_RUNTIME_DIR="+QString(getenv("XDG_RUNTIME_DIR")))
                                                << "bash"
                                                << "-c"
                                                << (script));
     process.waitForFinished(-1);

     show();

     QObject::sender()->setProperty("text","Instalar");

     if (QObject::sender()->property("checkInstall").toString().startsWith("/")) {
         QFile f(QObject::sender()->property("checkInstall").toString());
         if (f.exists()) QObject::sender()->setProperty("text","Remover");
     } else {
         std::string comando = QObject::sender()->property("checkInstall").toString().toStdString();
         int result = system(comando.c_str());
         if (WEXITSTATUS(result) == 0) QObject::sender()->setProperty("text","Remover");
     }
}

void Welcome::openLink(){
    QProcess process;
    process.start("xdg-open", QStringList() << QObject::property("url").toString());
    process.waitForFinished();
}
