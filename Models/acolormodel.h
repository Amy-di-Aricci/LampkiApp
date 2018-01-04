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
    virtual int GetRH() = 0;
    virtual int GetGS() = 0;
    virtual int GetBV() = 0;
    virtual void SetRH(int rh) = 0;
    virtual void SetGS(int gs) = 0;
    virtual void SetBV(int bv) = 0;
    virtual ~AColorModel() = default;
};

#endif // ACOLORMODEL_H
