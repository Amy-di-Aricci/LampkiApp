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

int RGBColorModel::GetRed()
{
    return red;
}

void RGBColorModel::SetRed(int r)
{
    red = r;
}

int RGBColorModel::GetGreen()
{
    return green;
}

void RGBColorModel::SetGreen(int g)
{
    green = g;
}

int RGBColorModel::GetBlue()
{
    return blue;
}

void RGBColorModel::SetBlue(int b)
{
    blue = b;
}
