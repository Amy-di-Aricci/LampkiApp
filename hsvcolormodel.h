#ifndef HSVCOLORMODEL_H
#define HSVCOLORMODEL_H

#include "acolormodel.h"
#include "rgbcolormodel.h"
#include <memory>
#include <QString>

class HSVColorModel : public AColorModel
{
    int hue;
    int saturation;
    int value;
public:
    HSVColorModel();
    HSVColorModel(int h, int s, int v);
    RGBColorModel ParseToRGB();
    std::unique_ptr<AColorModel> AsRGB() override;
    std::unique_ptr<AColorModel> AsHSV() override;
    QString AsHex();
    int GetHue();
    void SetHue(int h);
    int GetSaturation();
    void SetSaturation(int s);
    int GetValue();
    void SetValue(int v);
};

#endif // HSVCOLORMODEL_H
