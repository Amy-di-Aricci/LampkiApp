#include "hsvcolormodel.h"

HSVColorModel::HSVColorModel()
{
    hue = 0;
    saturation = 0;
    value = 100;
}

HSVColorModel::HSVColorModel(int h, int s, int v)
{
    hue = h;
    saturation = s;
    value = v;
}

AColorModel *HSVColorModel::AsRGB()
{
    return this;
}

AColorModel *HSVColorModel::AsHSV()
{
    return this;
}

QString HSVColorModel::AsHex()
{
    return "";
}

int HSVColorModel::GetHue()
{
    return hue;
}

void HSVColorModel::SetHue(int h)
{
    hue = h;
}

int HSVColorModel::GetSaturation()
{
    return saturation;
}

void HSVColorModel::SetSaturation(int s)
{
    saturation = s;
}

int HSVColorModel::GetValue()
{
    return value;
}

void HSVColorModel::SetValue(int v)
{
    value = v;
}
