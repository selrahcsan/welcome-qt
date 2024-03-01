#include "check.h"

check::check() {}

bool check::apps(std::string nameApp, std::string modeApp){
    if (modeApp == "debs"){
        std::string comando = "which " + nameApp;
        int result = system(comando.c_str());
        return WEXITSTATUS(result) == 0;
    }
    else if (modeApp == "flatpak"){
        std::string comando = "flatpak info " + nameApp;
        int result = system(comando.c_str());
        return WEXITSTATUS(result) == 0;

    }
    else if (modeApp == "webApps"){
        std::string username = getenv("USER");
        std::filesystem::path webApp ="/home/"+username+"/.local/share/applications/"+nameApp+".desktop";
        bool exist = std::filesystem::exists(webApp);
        return exist;
    }
    return false;
}

