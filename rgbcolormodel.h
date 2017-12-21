#ifndef RGBCOLORMODEL_H
#define RGBCOLORMODEL_H

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
    int GetRed();
    void SetRed(int r);
    int GetGreen();
    void SetGreen(int g);
    int GetBlue();
    void SetBlue(int b);
};

#endif // RGBCOLORMODEL_H
