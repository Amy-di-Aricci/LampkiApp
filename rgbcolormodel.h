#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include "acolormodel.h"
#include <QString>

class RGBColorModel : public AColorModel
{
    int red;
    int green;
    int blue;
public:
    RGBColorModel();
    RGBColorModel(int r, int g, int b);
    virtual AColorModel* AsRGB();
    virtual AColorModel* AsHSV();
    virtual QString AsHex();
    /*TODO: get, set*/
};

#endif // RGBCOLOR_H
