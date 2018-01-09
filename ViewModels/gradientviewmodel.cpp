#include "gradientviewmodel.h"
#include <memory>
QVector<QString> GradientViewModel::generateGradient()
{
    int diodeCount = 8;
    QVector<QString> gradient;
    RGBColorModel tempColor;
    for(int i = 0; i<diodeCount; i++)
    {
        tempColor.SetRH((diodeCount-i-1)/(double)(diodeCount-1)*(_firstColor->AsRGB()->GetRH()) + i/(double)(diodeCount-1)*(_secondColor->AsRGB()->GetRH()));
        tempColor.SetGS((diodeCount-i-1)/(double)(diodeCount-1)*(_firstColor->AsRGB()->GetGS()) + i/(double)(diodeCount-1)*(_secondColor->AsRGB()->GetGS()));
        tempColor.SetBV((diodeCount-i-1)/(double)(diodeCount-1)*(_firstColor->AsRGB()->GetBV()) + i/(double)(diodeCount-1)*(_secondColor->AsRGB()->GetBV()));
        gradient.push_back(tempColor.AsHex());
    }
    return gradient;
}

AColorModel &GradientViewModel::GetDiodeReferrence()
{
    switch(_selectedDiode)
    {
    case 0:
        return *_firstColor;
    case 1:
        return *_secondColor;
    }
}

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

int GradientViewModel::getSelectedType()
{
    return _selectedType;
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

void GradientViewModel::SendGradient()
{
    RestHelper& restHelper = RestHelper::getRestHelper();
    JSONHelper& jsonColor = JSONHelper::getJsonHelper();
    restHelper.SendColor(jsonColor.MulticolorToJson(_gradientVector), QString("/multicolor"));
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
    emit RHChanged(this->GetRH());
    emit GSChanged(this->GetGS());
    emit BVChanged(this->GetBV());

}

void GradientViewModel::setSelectedType(int type)
{
    switch(type)
    {
    case 0:
        _firstColor = std::move(_firstColor->AsHSV());
        _secondColor = std::move(_secondColor->AsHSV());
        _selectedType = type;
        emit selectedTypeChanged(type);
        break;
    case 1:
        _firstColor = std::move(_firstColor->AsRGB());
        _secondColor = std::move(_secondColor->AsRGB());
        _selectedType = type;
        emit selectedTypeChanged(type);
        break;
    default:
        break;
    }
}

void GradientViewModel::SetRH(int color)
{
    if(_selectedDiode == 0)
    {
        _firstColor->SetRH(color);
    }
    else if(_selectedDiode == 1)
    {
        _secondColor->SetRH(color);
    }
    _gradientVector = this->generateGradient();
    emit RHChanged(color);
    emit gradientVectorChanged(_gradientVector);
}

void GradientViewModel::SetGS(int color)
{
    if(_selectedDiode == 0)
    {
        _firstColor->SetGS(color);
    }
    else if(_selectedDiode == 1)
    {
        _secondColor->SetGS(color);
    }
    _gradientVector = this->generateGradient();
    emit GSChanged(color);
    emit gradientVectorChanged(_gradientVector);
}

void GradientViewModel::SetBV(int color)
{
    if(_selectedDiode == 0)
    {
        _firstColor->SetBV(color);
    }
    else if(_selectedDiode == 1)
    {
        _secondColor->SetBV(color);
    }
    _gradientVector = this->generateGradient();
    emit BVChanged(color);
    emit gradientVectorChanged(_gradientVector);
}
