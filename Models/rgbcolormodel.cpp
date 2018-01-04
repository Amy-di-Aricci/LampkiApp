#include "Models/rgbcolormodel.h"
#include "Models/hsvcolormodel.h"
#include <algorithm>
#include <sstream>
#include <ios>
#include <iomanip>
#include <cmath>

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
    const double r = red/255.0;
    const double g = green/255.0;
    const double b = blue/255.0;

    const double Cmax = std::max(r, std::max(g,b));
    const double Cmin = std::min(r, std::min(g,b));
    const double delta = Cmax - Cmin;

    int h = 0;
    int s = 0;
    int v = 0;

    //obliczanie skladowej Hue
    if(delta == 0)
        h = 0;
    else if (Cmax == r)
        h = 60*std::fmod(((g-b)/delta),6);
    else if (Cmax == g)
        h = 60*((b-r)/delta + 2);
    else if (Cmax == b)
        h = 60*((r-g)/delta + 4);

    //obliczanie skladowej Saturation
    if(Cmax != 0)
        s = (delta/Cmax)*100;

    //obliczanie skladowej Value
    v = Cmax*100;

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
    std::stringstream hexHelper;
    hexHelper << "#";
    hexHelper << std::setfill('0') << std::setw(2) << std::hex << this->GetRH();
    hexHelper << std::setfill('0') << std::setw(2) << std::hex << this->GetGS();
    hexHelper << std::setfill('0') << std::setw(2) << std::hex << this->GetBV();
    return QString::fromStdString(hexHelper.str());
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
