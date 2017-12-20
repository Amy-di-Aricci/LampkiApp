#include "colormodel.h"

ColorModel::ColorModel()
{
    hue = 0;
    saturation = 0;
    value = 0;
}

ColorModel::ColorModel(int h, int s, int v)
{
    hue = h;
    saturation = s;
    value = v;
}

int ColorModel::GetHue()
{
    return hue;
}

void ColorModel::SetHue(int h)
{
    hue = h;
}

int ColorModel::GetSaturation()
{
    return saturation;
}

void ColorModel::SetSaturation(int s)
{
    saturation = s;
}

int ColorModel::GetValue()
{
    return value;
}

void ColorModel::SetValue(int v)
{
    value = v;
}
