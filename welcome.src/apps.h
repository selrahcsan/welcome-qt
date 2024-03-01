#ifndef APPS_H
#define APPS_H

#include <start.h>

class apps
{
public:
    apps();

public slots:
    void installFlatpak(std::string nameApp, std::string nameWindow);
    void installDeb(std::string nameApp, std::string categorieApp);
    void installWebApps(std::string nameApp);
    void removeApp(std::string nameApp);
    void checkInstall(std::string nameApp, std::string modeApp);
};

#endif // APPS_H
