#include "ViewModels/colorviewmodel.h"
#include "Models/hsvcolormodel.h"
#include "Models/rgbcolormodel.h"
#include <memory>

ColorViewModel::ColorViewModel(QObject *parent) : QObject(parent)
{
    _colorModel = std::make_unique<HSVColorModel>(0, 100, 100);
}

int ColorViewModel::GetRH()
{
    return _colorModel->GetRH();
}

int ColorViewModel::GetGS()
{
    return _colorModel->GetGS();
}

int ColorViewModel::GetBV()
{
    return _colorModel->GetBV();
}

int ColorViewModel::GetTypeSelection()
{
    return this->_typeSelection;
}

QString ColorViewModel::GetHex()
{
    return _colorModel->AsHex();
}

void ColorViewModel::SetRH(int rh)
{
    _colorModel->SetRH(rh);
    emit RHChanged(rh);
}

void ColorViewModel::SetGS(int gs)
{
    _colorModel->SetGS(gs);
    emit GSChanged(gs);
}

void ColorViewModel::SetBV(int bv)
{
    _colorModel->SetBV(bv);
    emit BVChanged(bv);
}

void ColorViewModel::SetTypeSelection(int selection)
{
    switch(selection)
    {
    case 0:
        _colorModel = std::move(_colorModel->AsHSV());
        emit TypeSelectionChanged(selection);
        break;
    case 1:
        _colorModel = std::move(_colorModel->AsRGB());
        emit TypeSelectionChanged(selection);
        break;
    default:
        break;
    }
}

void ColorViewModel::SetHex(QString hex)
{
    emit HexChanged(hex);
}
