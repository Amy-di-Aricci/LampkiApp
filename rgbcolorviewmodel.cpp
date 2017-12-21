#include "rgbcolorviewmodel.h"

RGBColorViewModel::RGBColorViewModel(QObject *parent) : QObject(parent)
{
    _colorModel = RGBColorModel();
}

int RGBColorViewModel::Red()
{
    return _colorModel.GetRed();
}

int RGBColorViewModel::Green()
{
    return _colorModel.GetGreen();
}

int RGBColorViewModel::Blue()
{
    return _colorModel.GetBlue();
}

void RGBColorViewModel::setRed(int r)
{
    _colorModel.SetRed(r);
    emit RedChanged(r);
}

void RGBColorViewModel::setGreen(int g)
{
    _colorModel.SetGreen(g);
    emit GreenChanged(g);
}

void RGBColorViewModel::setBlue(int b)
{
    _colorModel.SetBlue(b);
    emit BlueChanged(b);
}
