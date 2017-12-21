#include "hsvcolorviewmodel.h"

HSVColorViewModel::HSVColorViewModel(QObject *parent) : QObject(parent)
{
    _colorModel = HSVColorModel();
}

int HSVColorViewModel::Hue()
{
    return _colorModel.GetHue();
}

int HSVColorViewModel::Saturation()
{
    return _colorModel.GetSaturation();
}

int HSVColorViewModel::Value()
{
    return _colorModel.GetValue();
}

void HSVColorViewModel::setHue(int h)
{
    _colorModel.SetHue(h);
    emit HueChanged(h);
}

void HSVColorViewModel::setSaturation(int s)
{
    _colorModel.SetSaturation(s);
    emit SaturationChanged(s);
}

void HSVColorViewModel::setValue(int v)
{
    _colorModel.SetValue(v);
    emit ValueChanged(v);
}

