#include "hsvcolorviewmodel.h"

HSVColorViewModel::HSVColorViewModel(QObject *parent) : QObject(parent)
{
    _colorModel = HSVColorModel();
    qDebug("Konstruktor");
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
    qDebug("Dzialam w srodku");
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

