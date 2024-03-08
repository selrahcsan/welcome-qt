#ifndef WELCOMEMAIN_H
#define WELCOMEMAIN_H

#include <QMainWindow>
#include <QPushButton>
#include <start.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class WelcomeMain;
}
QT_END_NAMESPACE

class WelcomeMain : public QMainWindow
{
    Q_OBJECT

public:
    WelcomeMain(QWidget *parent = nullptr);
    ~WelcomeMain();

private slots:

    //Elements BackEnds
    void check_Themes_Mode();
    void check_Colors_Mode();
    void check_Buttons_Texts(std::string appName, QPushButton *button, std::string modeApp);
    void check_All_buttons();
    void check_Button_remmina();
    void check_Button_clamtk();
    void check_Button_LibreOffice();
    void check_Button_WPS();
    void check_Button_Gdocs();
    void check_Button_Office365();
    void check_Button_GoogleChrome();
    void check_Button_Edge();
    void check_Button_Brave();
    void check_Button_Opera();
    void check_Button_Tor();
    void check_Button_Contacts();
    void check_Button_GoogleAgenda();
    void check_Button_GoogleKeep();
    void check_Button_CV2You();
    void check_Button_Githb();
    void check_Button_Gist();
    void check_Button_Glitch();
    void check_Button_CodePen();
    void check_Button_Diagrams();
    void check_Button_Gforms();
    void check_Button_AdobeExpress();
    void check_Button_Canva();
    void check_Button_LogoMaker();
    void check_Button_Photopeia();
    void check_Button_Photoshop();
    void check_Button_GoogleMeet();
    void check_Button_Medium();

    //Elements Inicial Page
    void on_listWidget_Categories_currentRowChanged(int currentRow);
    void on_pushButton_Drivers_clicked();
    void on_pushButton_Update_System_clicked();
    void on_pushButton_ClamTK_clicked();
    void on_pushButton_Remmina_clicked();
    void on_pushButton_Codecs_clicked();

    // Elements Office Page
    void on_pushButton_LibreOffice_clicked();
    void on_pushButton_WPS_clicked();
    void on_pushButton_Gdocs_clicked();
    void on_pushButton_Office_365_clicked();

    // Elements WebApps Page
    void on_pushButton_Contacts_clicked();
    void on_pushButton_GoogleAgenda_clicked();
    void on_pushButton_GoogleKeep_clicked();
    void on_pushButton_CV2You_clicked();
    void on_pushButton_Github_clicked();
    void on_pushButton_Gist_clicked();
    void on_pushButton_Glitch_clicked();

    // Element About Pages




    void on_pushButton_Gforms_clicked();

    void on_pushButton_AdobeExpress_clicked();

    void on_pushButton_Canva_clicked();

    void on_pushButton_LogoMaker_clicked();

    void on_pushButton_Photopea_clicked();

    void on_pushButton_Photoshop_clicked();

    void on_pushButton_GoogleMeet_clicked();

    void on_pushButton_Medium_clicked();

    void on_pushButton_Contribution_clicked();

    void on_pushButton_OficialSite_clicked();

    void on_pushButton_Youtube_clicked();

    void on_pushButton_Instagram_clicked();

    void on_pushButton_Google_clicked();

    void on_pushButton_ModeLight_clicked();

    void on_pushButton_ModeDark_clicked();

    void on_pushButton_Orange_clicked();

private:
    Ui::WelcomeMain *ui;

};
#endif // WELCOMEMAIN_H
