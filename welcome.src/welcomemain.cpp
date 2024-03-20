#include "welcomemain.h"
#include "ui_welcomemain.h"


WelcomeMain::WelcomeMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeMain)
{
    ui->setupUi(this);
    ui->listWidget_Categories->setCurrentRow(0);
    check_All_buttons();

}

//Elements BackEnds

void WelcomeMain::check_Themes_Mode(){
    checkTheme theme;
    QString LIGHT_THEME = "light";
    QString DARK_THEME = "dark";
    QString DEFAULT = "default";

    QString currentTheme = theme.getTheme();

    ui->pushButton_ModeDark->setFlat(currentTheme == LIGHT_THEME);
    ui->pushButton_ModeLight->setFlat(currentTheme == DARK_THEME);
    ui->pushButton_ModeLight->setFlat(currentTheme == DEFAULT);

    if (theme.getTheme() == "light"){
        ui->pushButton_ModeDark->setFlat(true);
        ui->pushButton_ModeLight->setFlat(false);
    }
    else if (theme.getTheme() == "dark")
    {
        ui->pushButton_ModeLight->setFlat(true);
        ui->pushButton_ModeDark->setFlat(false);
    }
    else
    {
        ui->pushButton_ModeDark->setFlat(true);
        ui->pushButton_ModeLight->setFlat(false);
    }


}

void WelcomeMain::check_Colors_Mode(){
    checkTheme color;
    if (color.getIcon() == "orange"){
        ui->pushButton_Orange->setFlat(false);
        ui->pushButton_Brown->setFlat(true);
        ui->pushButton_Cyan->setFlat(true);
        ui->pushButton_Lavanda->setFlat(true);
    }
    else if (color.getIcon() == "brown"){
        ui->pushButton_Orange->setFlat(true);
        ui->pushButton_Brown->setFlat(false);
        ui->pushButton_Cyan->setFlat(true);
        ui->pushButton_Lavanda->setFlat(true);
    }
    else if (color.getIcon() == "cyan")
    {
        ui->pushButton_Orange->setFlat(true);
        ui->pushButton_Brown->setFlat(true);
        ui->pushButton_Cyan->setFlat(false);
        ui->pushButton_Lavanda->setFlat(true);
    }
    else if (color.getIcon() == "lavanda")
    {
        ui->pushButton_Orange->setFlat(true);
        ui->pushButton_Brown->setFlat(true);
        ui->pushButton_Cyan->setFlat(true);
        ui->pushButton_Lavanda->setFlat(false);
    }
    else
    {
        ui->pushButton_Orange->setFlat(false);
        ui->pushButton_Brown->setFlat(true);
        ui->pushButton_Cyan->setFlat(true);
        ui->pushButton_Lavanda->setFlat(true);
    }


}

void WelcomeMain::on_listWidget_Categories_currentRowChanged(int currentRow)
{
    ui->stackedWidget_Pages->setCurrentIndex(currentRow);
}

void WelcomeMain::check_Buttons_Texts(std::string appName, QPushButton *button, std::string modeApp){
    check checks;
    bool statusApp = checks.apps(appName, modeApp);
    QString QappName = QString::fromStdString(appName);

    if (QappName == "clamtk")
    {
        QappName = "antivirus";
    }
    else if (QappName == "org.remmina.Remmina"){
        QappName = "remmina";
    }
    else
    {
        QappName = " ";
    }

    QappName.replace(0, 1, QappName.at(0).toUpper());
    button->setText(statusApp ? "Remover " + QappName : "Instalar " + QappName);
}

void WelcomeMain::check_All_buttons(){
    check_Themes_Mode();
    check_Button_remmina();
    check_Button_clamtk();
    check_Button_LibreOffice();
    check_Button_WPS();
    check_Button_Gdocs();
    check_Button_Office365();
    check_Button_GoogleChrome();
    check_Button_Edge();
    check_Button_Brave();
    check_Button_Opera();
    check_Button_Tor();
    check_Button_Contacts();
    check_Button_GoogleAgenda();
    check_Button_GoogleKeep();
    check_Button_CV2You();
    check_Button_Githb();
    check_Button_Gist();
    check_Button_Glitch();
    check_Button_CodePen();
    check_Button_Diagrams();
    check_Button_Gforms();
    check_Button_AdobeExpress();
    check_Button_Canva();
    check_Button_LogoMaker();
    check_Button_Photopeia();
    check_Button_Photoshop();
    check_Button_GoogleMeet();
    check_Button_Medium();
}

void WelcomeMain::check_Button_remmina(){
    check_Buttons_Texts("org.remmina.Remmina", ui->pushButton_Remmina, "flatpak");
}

void WelcomeMain::check_Button_clamtk(){
    check_Buttons_Texts("clamtk", ui->pushButton_ClamTK, "debs");
}

void WelcomeMain::check_Button_LibreOffice(){
    check_Buttons_Texts("libreoffice", ui->pushButton_LibreOffice, "debs");
}

void WelcomeMain::check_Button_WPS(){
    check_Buttons_Texts("wps", ui->pushButton_WPS, "debs");
}

void WelcomeMain::check_Button_Gdocs(){
    check_Buttons_Texts("gdocs", ui->pushButton_Gdocs, "webApps");
}

void WelcomeMain::check_Button_Office365(){
    check_Buttons_Texts("ms-365-electron", ui->pushButton_Office_365, "debs");
}

void WelcomeMain::check_Button_GoogleChrome(){
    check_Buttons_Texts("google-chrome-stable", ui->pushButton_Google, "debs");
}

void WelcomeMain::check_Button_Edge(){
    check_Buttons_Texts("com.microsoft.Edge",ui->pushButton_Edge, "flatpak");
}

void WelcomeMain::check_Button_Brave(){
    check_Buttons_Texts("brave-browser", ui->pushButton_Brave, "debs");
}

void WelcomeMain::check_Button_Opera(){
    check_Buttons_Texts("opera-stable", ui->pushButton_Opera, "debs");
}

void WelcomeMain::check_Button_Tor(){
    check_Buttons_Texts("com.github.micahflee.torbrowser-launcher", ui->pushButton_Tor, "flatpak");
}

void WelcomeMain::check_Button_Contacts(){
    check_Buttons_Texts("gcontacs", ui->pushButton_Contacts, "webApps");
}

void WelcomeMain::check_Button_GoogleAgenda(){
    check_Buttons_Texts("gcalendar", ui->pushButton_GoogleAgenda, "webApps");
}

void WelcomeMain::check_Button_GoogleKeep(){
    check_Buttons_Texts("gkeep", ui->pushButton_GoogleKeep, "webApps");
}

void WelcomeMain::check_Button_CV2You(){
    check_Buttons_Texts("cvyou", ui->pushButton_CV2You, "webApps");
}

void WelcomeMain::check_Button_Githb(){
    check_Buttons_Texts("github", ui->pushButton_Github, "webApps");
}

void WelcomeMain::check_Button_Gist(){
    check_Buttons_Texts("gist", ui->pushButton_Gist, "webApps");
}

void WelcomeMain::check_Button_Glitch(){
    check_Buttons_Texts("glitch", ui->pushButton_Glitch, "webApps");
}

void WelcomeMain::check_Button_CodePen(){
    check_Buttons_Texts("codepen", ui->pushButton_CodePen, "webApps");
}

void WelcomeMain::check_Button_Diagrams(){
    check_Buttons_Texts("diagrams", ui->pushButton_Diagrams, "webApps");
}

void WelcomeMain::check_Button_Gforms(){
    check_Buttons_Texts("gforms", ui->pushButton_Gforms, "webApps");
}

void WelcomeMain::check_Button_AdobeExpress(){
    check_Buttons_Texts("gforms", ui->pushButton_AdobeExpress, "webApps");
}

void WelcomeMain::check_Button_Canva(){
    check_Buttons_Texts("canva", ui->pushButton_Canva, "webApps");
}

void WelcomeMain::check_Button_LogoMaker(){
    check_Buttons_Texts("logomaker", ui->pushButton_LogoMaker, "webApps");
}

void WelcomeMain::check_Button_Photopeia(){
    check_Buttons_Texts("photopeia", ui->pushButton_Photopea, "webApps");
}

void WelcomeMain::check_Button_Photoshop(){
    check_Buttons_Texts("photoshop", ui->pushButton_Photoshop, "webApps");
}

void WelcomeMain::check_Button_GoogleMeet(){
    check_Buttons_Texts("gmeet", ui->pushButton_GoogleMeet, "webApps");
}

void WelcomeMain::check_Button_Medium(){
    check_Buttons_Texts("medium", ui->pushButton_Medium, "webApps");
}

//Elements Inicial Page

void WelcomeMain::on_pushButton_Drivers_clicked()
{
    // system("pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY software-properties-qt --open-tab=4");
    QProcess process;
    process.start("pkexec", QStringList() << "env" << "software-properties-qt" << "--open-tab=4");
    //"DISPLAY=$DISPLAY" << "XAUTHORITY=$XAUTHORITY"
    process.waitForFinished();

}

void WelcomeMain::on_pushButton_Update_System_clicked()
{
    QProcess process;
    process.start("plasma-discover", QStringList() << "--mode" << "update");
    process.waitForFinished();
}

void WelcomeMain::on_pushButton_ClamTK_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_ClamTK->text();

    if (checkInstall == "Instalar Antivirus"){
        actionApp.installDeb("clamav", "tarefasAdicionais");
    }
    else{
        actionApp.removeApp("clamav");
    }
    check_Button_clamtk();
}

void WelcomeMain::on_pushButton_Remmina_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Remmina->text();

    if (checkInstall == "Instalar Remmina"){
        actionApp.installFlatpak("org.remmina.Remmina", "Remmina");
    }
    else{
        actionApp.removeApp("remmina");
    }
    check_Button_remmina();
}

void WelcomeMain::on_pushButton_Codecs_clicked()
{
    apps actionApp;
    actionApp.installDeb("wrapper-codecs", "tarefasAdicionais");
}

void WelcomeMain::on_pushButton_ModeLight_clicked()
{
    checkTheme themes;
    std::string color = themes.getIcon().toStdString();
    themes.setTheme(color,"Light");
    check_Themes_Mode();
}


void WelcomeMain::on_pushButton_ModeDark_clicked()
{
    checkTheme themes;
    std::string color = themes.getIcon().toStdString();
    themes.setTheme(color,"Light");
    check_Themes_Mode();
}


void WelcomeMain::on_pushButton_Orange_clicked()
{
    checkTheme themes;
    std::string mode = themes.getTheme().toStdString();
    themes.setTheme("Orange", mode);
}


// Elements Office Page

void WelcomeMain::on_pushButton_LibreOffice_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_LibreOffice->text();

    if (checkInstall == "Instalar  "){
        actionApp.installDeb("libreoffice", "office");
    }
    else{
        actionApp.removeApp("libreoffice");
    }
    check_Button_LibreOffice();
}

void WelcomeMain::on_pushButton_WPS_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_WPS->text();

    if (checkInstall == "Instalar  "){
        actionApp.installDeb("wps", "office");
    }
    else{
        actionApp.removeApp("wps");
    }
    check_Button_WPS();
}

void WelcomeMain::on_pushButton_Gdocs_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Gdocs->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("gdocs");
    }
    else{
        actionApp.removeApp("gdocs");
    }
    check_Button_Gdocs();
}

void WelcomeMain::on_pushButton_Office_365_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Office_365->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("office365");
    }
    else{
        actionApp.removeApp("office365");
    }
    check_Button_Office365();
}

// Elements WebApps Page

// Tab Acessórios

void WelcomeMain::on_pushButton_Contacts_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Contacts->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("gcontacts");
    }
    else{
        actionApp.removeApp("gcontacts");
    }
    check_Button_Contacts();
}

void WelcomeMain::on_pushButton_GoogleAgenda_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_GoogleAgenda->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("gcontacts");
    }
    else{
        actionApp.removeApp("gcontacts");
    }
    check_Button_GoogleAgenda();
}

void WelcomeMain::on_pushButton_GoogleKeep_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_GoogleKeep->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("gkeep");
    }
    else{
        actionApp.removeApp("gkeep");
    }
    check_Button_GoogleKeep();
}

void WelcomeMain::on_pushButton_CV2You_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_GoogleKeep->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("cvyou");
    }
    else{
        actionApp.removeApp("cvyou");
    }
    check_Button_CV2You();
}

// Tab Desenvolvimento

void WelcomeMain::on_pushButton_Github_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Github->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("github");
    }
    else{
        actionApp.removeApp("github");
    }
    check_Button_Githb();
}

void WelcomeMain::on_pushButton_Gist_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Gist->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("gist");
    }
    else{
        actionApp.removeApp("gist");
    }
}

void WelcomeMain::on_pushButton_Glitch_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Glitch->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("glitch");
    }
    else{
        actionApp.removeApp("glitch");
    }
}

// Tab Escritório

void WelcomeMain::on_pushButton_Gforms_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Gforms->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("gforms");
    }
    else{
        actionApp.removeApp("gforms");
    }
}

void WelcomeMain::on_pushButton_AdobeExpress_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_AdobeExpress->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("spark");
    }
    else{
        actionApp.removeApp("spark");
    }
    check_Button_AdobeExpress();
}

void WelcomeMain::on_pushButton_Canva_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_AdobeExpress->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("canva");
    }
    else{
        actionApp.removeApp("canva");
    }
    check_Button_Canva();
}

void WelcomeMain::on_pushButton_LogoMaker_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_LogoMaker->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("logomaker");
    }
    else{
        actionApp.removeApp("logomaker");
    }
    check_Button_LogoMaker();
}

void WelcomeMain::on_pushButton_Photopea_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Photopea->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("photopea");
    }
    else{
        actionApp.removeApp("photopea");
    }
    check_Button_Photopeia();
}

void WelcomeMain::on_pushButton_Photoshop_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Photoshop->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("photoshop");
    }
    else{
        actionApp.removeApp("photoshop");
    }
    check_Button_Photoshop();
}

void WelcomeMain::on_pushButton_GoogleMeet_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_GoogleMeet->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("gmeet");
    }
    else{
        actionApp.removeApp("gmeet");
    }
    check_Button_GoogleMeet();
}

void WelcomeMain::on_pushButton_Medium_clicked()
{
    apps actionApp;
    QString checkInstall = ui->pushButton_Medium->text();

    if (checkInstall == "Instalar  "){
        actionApp.installWebApps("medium");
    }
    else{
        actionApp.removeApp("medium");
    }
    check_Button_Medium();
}

// Elements About Page

void WelcomeMain::on_pushButton_Contribution_clicked()
{
    openLink("https://www.padrim.com.br/mestresemlinux");
}

void WelcomeMain::on_pushButton_OficialSite_clicked()
{
    openLink("https://tigeros.com.br/");
}

void WelcomeMain::on_pushButton_Youtube_clicked()
{
    openLink("https://youtube.com/mestresemlinux");
}

void WelcomeMain::on_pushButton_Instagram_clicked()
{
    openLink("https://www.instagram.com/mestresemlinux/");
}

WelcomeMain::~WelcomeMain()
{
    delete ui;
}


void WelcomeMain::on_pushButton_Google_clicked()
{

}


