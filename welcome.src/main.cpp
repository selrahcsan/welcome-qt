#include "welcomemain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WelcomeMain w;
    w.show();
    return a.exec();
}
