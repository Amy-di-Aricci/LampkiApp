#include "hsvcolorviewmodel.h"

HSVColorViewModel::HSVColorViewModel(QObject *parent) : QObject(parent)
{
    _colorModel = HSVColorModel();
}

int HSVColorViewModel::Hue()
{
    return _colorModel.GetRH();
}

int HSVColorViewModel::Saturation()
{
    return _colorModel.GetGS();
}

int HSVColorViewModel::Value()
{
    return _colorModel.GetBV();
}

void HSVColorViewModel::setHue(int h)
{
    _colorModel.SetRH(h);
    emit HueChanged(h);
}

void HSVColorViewModel::setSaturation(int s)
{
    _colorModel.SetGS(s);
    emit SaturationChanged(s);
}

void HSVColorViewModel::setValue(int v)
{
    _colorModel.SetBV(v);
    emit ValueChanged(v);
}

