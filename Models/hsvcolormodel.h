#ifndef HSVCOLORMODEL_H
#define HSVCOLORMODEL_H

#include "Models/acolormodel.h"
#include <memory>
#include <QString>

class RGBColorModel;
class HSVColorModel : public AColorModel
{
    int hue;
    int saturation;
    int value;
public:
    HSVColorModel();
    HSVColorModel(int h, int s, int v);
    std::unique_ptr<RGBColorModel> ParseToRGB();
    std::unique_ptr<AColorModel> AsRGB() override;
    std::unique_ptr<AColorModel> AsHSV() override;
    QString AsHex();
    int GetRH() override;
    int GetGS() override;
    int GetBV() override;
    void SetRH(int rh) override;
    void SetGS(int gs) override;
    void SetBV(int bv) override;
};

#endif // HSVCOLORMODEL_H
