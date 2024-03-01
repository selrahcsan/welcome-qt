#include "apps.h"

apps::apps() {}

void apps::installDeb(std::string nameApp, std::string categorieApp){
    std::string commandString = "pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY $PWD/" + categorieApp + "/" + nameApp + ".sh";
    std::system(commandString.c_str());
}

void apps::installFlatpak(std::string nameApp, std::string nameWindow){
    std::string commandString = "flatpak-install-gui --override-appname="+nameWindow+" "+nameApp;
    std::system(commandString.c_str());
}

void apps::installWebApps(std::string nameApp){
    std::string commandString = "$PWD/install.sh "+nameApp;
    std::system(commandString.c_str());
}

void apps::removeApp(std::string nameApp){
    std::string commandString = "pkexec env DISPLAY=$DISPLAY XAUTHORITY=$XAUTHORITY $PWD/remove.sh  "+nameApp;
    std::system(commandString.c_str());
}

