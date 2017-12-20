#ifndef ACOLORMODEL_H
#define ACOLORMODEL_H

#include <QString>


class AColorModel
{
public:
    virtual AColorModel* AsRGB() = 0;
    virtual AColorModel* AsHSV() = 0;
    virtual QString AsHex() = 0;
};

#endif // ACOLORMODEL_H
