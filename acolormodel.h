#ifndef ACOLORMODEL_H
#define ACOLORMODEL_H

#include <QString>
#include <memory>

class AColorModel
{
public:
    virtual std::unique_ptr<AColorModel> AsRGB() = 0;
    virtual std::unique_ptr<AColorModel> AsHSV() = 0;
    virtual QString AsHex() = 0;
    virtual ~AColorModel();
};

#endif // ACOLORMODEL_H
