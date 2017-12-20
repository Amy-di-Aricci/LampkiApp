#ifndef HSVCOLORMODEL_H
#define HSVCOLORMODEL_H

#include "acolormodel.h"
#include <QString>

class HSVColorModel : public AColorModel
{
    int hue;
    int saturation;
    int value;
public:
    HSVColorModel();
    HSVColorModel(int h, int s, int v);
    AColorModel* AsRGB() override;
    AColorModel* AsHSV() override;
    QString AsHex();
    int GetHue();
    void SetHue(int h);
    int GetSaturation();
    void SetSaturation(int s);
    int GetValue();
    void SetValue(int v);
};

#endif // HSVCOLORMODEL_H
