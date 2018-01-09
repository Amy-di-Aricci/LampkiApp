#include "Models/hsvcolormodel.h"
#include "Models/rgbcolormodel.h"
#include "Models/acolormodel.h"
#include <math.h>
#include <sstream>
#include <ios>
#include <iomanip>

HSVColorModel::HSVColorModel()
{
    hue = 0;
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
    const double h = (hue%360)/60.0;
    const double s = saturation/100.0;
    const double v = value/100.0;

    const double C = s*v;
    const double X = C*(1 - std::abs(std::fmod(h,2) - 1));
    const double m = v-C;

    double r = 0;
    double g = 0;
    double b = 0;

    int helper = h;
    switch(helper) //rozpatrywane przypadki dla 60-stopniowych zakresow
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
    std::unique_ptr<AColorModel> RGBhelper = this->AsRGB();
    std::stringstream hexHelper;
    hexHelper << "#";
    hexHelper << std::setfill('0') << std::setw(2) << std::hex << RGBhelper->GetRH();
    hexHelper << std::setfill('0') << std::setw(2) << std::hex << RGBhelper->GetGS();
    hexHelper << std::setfill('0') << std::setw(2) << std::hex << RGBhelper->GetBV();
    return QString::fromStdString(hexHelper.str());
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
