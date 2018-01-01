#ifndef RGBCOLORMODEL_H
#define RGBCOLORMODEL_H

#include "acolormodel.h"
#include <QString>
#include <memory>

class RGBColorModel : public AColorModel
{
    int red;
    int green;
    int blue;
public:
    RGBColorModel();
    RGBColorModel(int r, int g, int b);
    std::unique_ptr<AColorModel> AsRGB() override;
    std::unique_ptr<AColorModel> AsHSV() override;
    QString AsHex() override;
    int GetRed();
    void SetRed(int r);
    int GetGreen();
    void SetGreen(int g);
    int GetBlue();
    void SetBlue(int b);
};

#endif // RGBCOLORMODEL_H
