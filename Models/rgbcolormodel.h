#ifndef RGBCOLORMODEL_H
#define RGBCOLORMODEL_H

#include "Models/acolormodel.h"
#include <QString>
#include <memory>
class HSVColorModel;
class RGBColorModel : public AColorModel
{
    int red;
    int green;
    int blue;
public:
    RGBColorModel();
    RGBColorModel(int r, int g, int b);
    std::unique_ptr<HSVColorModel> ParseToHSV();
    std::unique_ptr<AColorModel> AsRGB() override;
    std::unique_ptr<AColorModel> AsHSV() override;
    QString AsHex() override;
    int GetRH() override;
    int GetGS() override;
    int GetBV() override;
    void SetRH(int rh) override;
    void SetGS(int gs) override;
    void SetBV(int bv) override;
};

#endif // RGBCOLORMODEL_H
