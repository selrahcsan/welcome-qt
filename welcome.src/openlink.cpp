#include "openlink.h"

openLink::openLink(QString url) {
    QProcess process;
    process.start("xdg-open", QStringList() << url);
    process.waitForFinished();
}
