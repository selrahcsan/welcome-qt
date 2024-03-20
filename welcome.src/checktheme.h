#ifndef CHECKTHEME_H
#define CHECKTHEME_H

#include "start.h"

class checkTheme
{
public:
    checkTheme();

public slots:
    QString getTheme();
    void setTheme(std::string color, std::string mode);
    QString getIcon();
    void setIcon();
    void setColor();
};

#endif // CHECKTHEME_H
