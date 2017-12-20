#include "colorviewmodel.h"

ColorViewModel::ColorViewModel(QObject *parent) : QObject(parent)
{
    _colorModel = ColorModel();
    qDebug("Konstruktor");
}

int ColorViewModel::Hue()
{
    return _colorModel.GetHue();
}

int ColorViewModel::Saturation()
{
    return _colorModel.GetSaturation();
}

int ColorViewModel::Value()
{
    return _colorModel.GetValue();
}

void ColorViewModel::setHue(int h)
{
    _colorModel.SetHue(h);
    qDebug("Dzialam w srodku");
    emit HueChanged(h);
}

void ColorViewModel::setSaturation(int s)
{
    _colorModel.SetSaturation(s);
    emit SaturationChanged(s);
}

void ColorViewModel::setValue(int v)
{
    _colorModel.SetValue(v);
    emit ValueChanged(v);
}

