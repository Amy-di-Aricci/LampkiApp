#include "gradientviewmodel.h"

GradientViewModel::GradientViewModel(QObject *parent) : QObject(parent)
{
    _selectedDiode = 0;
    _firstColor = std::make_unique<HSVColorModel>(0, 100, 100);
    _secondColor = std::make_unique<HSVColorModel>(0, 100, 100);
    for(int i = 0; i < 8; i++)
    {
        _gradientVector.push_back(QString("#ff0000"));
    }
}

QVector<QString> GradientViewModel::getGradientVector()
{
    return _gradientVector;
}

int GradientViewModel::getSelectedDiode()
{
    return _selectedDiode;
}

int GradientViewModel::GetRH()
{
    if(_selectedDiode == 0)
        return _firstColor->GetRH();
    else if(_selectedDiode == 1)
        return _secondColor->GetRH();

}

int GradientViewModel::GetGS()
{
    if(_selectedDiode == 0)
        return _firstColor->GetGS();
    else if(_selectedDiode == 1)
        return _secondColor->GetGS();
}

int GradientViewModel::GetBV()
{
    if(_selectedDiode == 0)
        return _firstColor->GetBV();
    else if(_selectedDiode == 1)
        return _secondColor->GetBV();
}

void GradientViewModel::setGradientVector(QVector<QString> vect)
{
    _gradientVector = vect;
    emit gradientVectorChanged(vect);
}

void GradientViewModel::setSelectedDiode(int diode)
{
    _selectedDiode = diode;
    emit selectedDiodeChanged(diode);
}

void GradientViewModel::SetRH(int color)
{
    if(_selectedDiode == 0)
    {
        _firstColor->SetRH(color);
        _gradientVector[0] = _firstColor->AsHex();
    }
    else if(_selectedDiode == 1)
    {
        _secondColor->SetRH(color);
    }
    emit RHChanged(color);
    emit gradientVectorChanged(_gradientVector);
}

void GradientViewModel::SetGS(int color)
{
    if(_selectedDiode == 0)
    {
        _firstColor->SetGS(color);
        _gradientVector[0] = _firstColor->AsHex();
    }
    else if(_selectedDiode == 1)
    {
        _secondColor->SetGS(color);
    }
    emit GSChanged(color);
    emit gradientVectorChanged(_gradientVector);
}

void GradientViewModel::SetBV(int color)
{
    if(_selectedDiode == 0)
    {
        _firstColor->SetBV(color);
        _gradientVector[0] = _firstColor->AsHex();
    }
    else if(_selectedDiode == 1)
    {
        _secondColor->SetBV(color);
    }
    emit BVChanged(color);
    emit gradientVectorChanged(_gradientVector);
}
