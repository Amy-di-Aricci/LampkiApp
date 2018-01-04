#include "Models/rgbcolormodel.h"
#include "Models/hsvcolormodel.h"
#include <algorithm>

RGBColorModel::RGBColorModel()
{
    red = 255;
    green = 0;
    blue = 0;
}

RGBColorModel::RGBColorModel(int r, int g, int b)
{
    red = r;
    green = g;
    blue = b;
}

std::unique_ptr<HSVColorModel> RGBColorModel::ParseToHSV()
{
    //inicjalizacja zmiennych pomocniczych
    const int r = red/255;
    const int g = green/255;
    const int b = blue/255;

    const int Cmax = std::max(r, std::max(g,b));
    const int Cmin = std::min(r, std::min(g,b));
    const int delta = Cmax - Cmin;

    int h = 0;
    int s = 0;
    int v = 0;

    //obliczanie skladowej Hue
    if(delta == 0)
        h = 0;
    else if (Cmax == r)
        h = 60*(((g-b)/delta)%6);
    else if (Cmax == g)
        h = 60*((b-r)/delta + 2);
    else if (Cmax == b)
        h = 60*((r-g)/delta + 4);

    //obliczanie skladowej Saturation
    if(Cmax != 0)
        s = delta/Cmax;

    //obliczanie skladowej Value
    v = Cmax;

    return std::make_unique<HSVColorModel>(h, s, v);
}

std::unique_ptr<AColorModel>RGBColorModel::AsRGB()
{
    return std::make_unique<RGBColorModel>(this->red, this->green, this->blue);
}

std::unique_ptr<AColorModel>RGBColorModel::AsHSV()
{
    return this->ParseToHSV();
}

QString RGBColorModel::AsHex()
{
    return "";
}

int RGBColorModel::GetRH()
{
    return red;
}

int RGBColorModel::GetGS()
{
    return green;
}

int RGBColorModel::GetBV()
{
    return blue;
}

void RGBColorModel::SetRH(int rh)
{
    red = rh;
}

void RGBColorModel::SetGS(int gs)
{
    green = gs;
}

void RGBColorModel::SetBV(int bv)
{
    blue = bv;
}
