#include "Models/hsvcolormodel.h"
#include "Models/rgbcolormodel.h"
#include "Models/acolormodel.h"
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
    const int h = (hue%360)/60;
    const int s = saturation/100;
    const int v = value/100;

    const int C = s*v;
    const int X = C*(1 - std::abs(h % 2 - 1));
    const int m = v-C;

    int r = 0;
    int g = 0;
    int b = 0;

    switch(h) //rozpatrywane przypadki dla 60-stopniowych zakresow
    {
        case 0:
        r = C;
        g = X;
        b = 0;
        break;
    case 1:
        r = X;
        g = C;
        b = 0;
        break;
    case 2:
        r = 0;
        g = C;
        b = X;
        break;
    case 3:
        r = 0;
        g = X;
        b = C;
        break;
    case 4:
        r = X;
        g = 0;
        b = C;
        break;
    case 5:
        r = C;
        g = 0;
        b = X;
        break;
    default:
        break;
    }

    int rgb[3] = {(r+m)*255, (g+m)*255, (b+m)*255};

    return std::make_unique<RGBColorModel>(rgb[0], rgb[1], rgb[2]);
}

std::unique_ptr<AColorModel> HSVColorModel::AsRGB()
{
    return this->ParseToRGB();
}

std::unique_ptr<AColorModel> HSVColorModel::AsHSV()
{
    return std::make_unique<HSVColorModel>(this->hue, this->saturation, this->value);
}

QString HSVColorModel::AsHex()
{
    return "";
}

void HSVColorModel::SetRH(int rh)
{
    hue = rh;
}

void HSVColorModel::SetGS(int gs)
{
    saturation = gs;
}

void HSVColorModel::SetBV(int bv)
{
    value = bv;
}

int HSVColorModel::GetRH()
{
    return hue;
}

int HSVColorModel::GetGS()
{
    return saturation;
}

int HSVColorModel::GetBV()
{
    return value;
}
