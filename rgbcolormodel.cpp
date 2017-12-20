#include "rgbcolormodel.h"

RGBColorModel::RGBColorModel()
{
    red = 255;
    green = 255;
    blue = 255;
}

RGBColorModel::RGBColorModel(int r, int g, int b)
{
    red = r;
    green = g;
    blue = b;
}

AColorModel *RGBColorModel::AsRGB()
{
    return this;
}

AColorModel *RGBColorModel::AsHSV()
{
    return this;
}

QString RGBColorModel::AsHex()
{
    return "";
}
