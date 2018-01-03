#include "hsvcolormodel.h"
#include "rgbcolormodel.h"
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
    int h = hue/60;
    int s = saturation/100;
    int v = value/100;

    int C = s*v;
    int X = C*(1 - std::abs(h % 2 - 1));
    int m = v-C;

    int rgbprim[3] = {0,0,0};

    switch(h)
    {
        case 0:
        //rgbprim = {C,X,0};
        rgbprim[0] = C;
        rgbprim[1] = X;
        rgbprim[2] = 0;
        break;
    case 1:
        //rgbprim = {X,C,0};
        rgbprim[0] = X;
        rgbprim[1] = C;
        rgbprim[2] = 0;
        break;
    case 2:
        //rgbprim = {0,C,X};
        rgbprim[0] = 0;
        rgbprim[1] = C;
        rgbprim[2] = X;
        break;
    case 3:
        //rgbprim = {0,X,C};
        rgbprim[0] = 0;
        rgbprim[1] = X;
        rgbprim[2] = C;
        break;
    case 4:
        //rgbprim = {X,0,C};
        rgbprim[0] = X;
        rgbprim[1] = 0;
        rgbprim[2] = C;
        break;
    case 5:
        //rgbprim = {C,0,X};
        rgbprim[0] = C;
        rgbprim[1] = 0;
        rgbprim[2] = X;
        break;
    default:
        break;
    }

    int rgb[3] = {(rgbprim[0]+m)*255, (rgbprim[1]+m)*255, (rgbprim[2]+m)*255};

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
