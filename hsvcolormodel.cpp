#include "hsvcolormodel.h"
#include <math.h>

HSVColorModel::HSVColorModel()
{
    hue = 60;
    saturation = 100;
    value = 100;
}

HSVColorModel::HSVColorModel(int h, int s, int v)
{
    hue = h;
    saturation = s;
    value = v;
}

std::unique_ptr<RGBColorModel> HSVColorModel::ParseToRGB()
{
    int h = this->hue/60;
    int s = (this->saturation)/100;
    int v = (this->value)/100;

    int C = s*v;
    int X = C*(1 - std::abs(h % 2 - 1));
    int m = v-C;

    int rgbprim[3];
    int rgb[3];

    switch(h)
    {
        case 0:
        rgbprim = {C,X,0};
        break;
    case 1:
        rgbprim = {X,C,0};
        break;
    case 2:
        rgbprim = {0,C,X};
        break;
    case 3:
        rgbprim = {0,X,C};
        break;
    case 4:
        rgbprim = {X,0,C};
        break;
    case 5:
        rgbprim = {C,0,X};
        break;
    default:
        rgbprim = {0,0,0};
    }

    rgb = {(rgbprim[0]+m)*255, (rgbprim[1]+m)*255, (rgbprim[2]+m)*255};

    return std::make_unique<RGBColorModel>(rgb[0], rgb[1], rgb[2]);
}

std::unique_ptr<AColorModel> HSVColorModel::AsRGB()
{
    return this->ParseToRGB();
}

std::unique_ptr<AColorModel> HSVColorModel::AsHSV()
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
