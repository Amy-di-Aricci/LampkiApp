#include "ViewModels/colorviewmodel.h"
#include "Models/hsvcolormodel.h"
#include "Models/rgbcolormodel.h"
#include "Models/acolormodel.h"
#include <memory>
#include <QJsonDocument>
#include <QDebug>

ColorViewModel::ColorViewModel(QObject *parent) : QObject(parent)
{
    _colorModel = std::make_unique<HSVColorModel>(0, 100, 100);
    _typeSelection = 0;
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

void ColorViewModel::SendUnicolor()
{
    //QJsonDocument jsonDoc = jsonColor.ParseToJson(*_colorModel);
    restHelper.SendColor(jsonColor.UnicolorToJson(*_colorModel), QString("/unicolor"));
}

void ColorViewModel::SetRH(int rh)
{
    _colorModel->SetRH(rh);
    emit RHChanged(rh);
    emit hexChanged(_colorModel->AsHex());
}

void ColorViewModel::SetGS(int gs)
{
    _colorModel->SetGS(gs);
    emit GSChanged(gs);
    emit hexChanged(_colorModel->AsHex());
}

void ColorViewModel::SetBV(int bv)
{
    _colorModel->SetBV(bv);
    emit BVChanged(bv);
    emit hexChanged(_colorModel->AsHex());
}

void ColorViewModel::SetTypeSelection(int selection)
{
    qDebug() << "Selection: " << selection;
    switch(selection)
    {
    case 0:
        _colorModel = std::move(_colorModel->AsHSV());
        emit typeSelectionChanged(selection);
        emit RHChanged(_colorModel->GetRH());
        emit GSChanged(_colorModel->GetGS());
        emit BVChanged(_colorModel->GetBV());
        _typeSelection = selection;
        break;
    case 1:
        _colorModel = std::move(_colorModel->AsRGB());
        emit typeSelectionChanged(selection);
        emit RHChanged(_colorModel->GetRH());
        emit GSChanged(_colorModel->GetGS());
        emit BVChanged(_colorModel->GetBV());
        _typeSelection = selection;
        break;
    default:
        break;
    }
}

void ColorViewModel::SetHex(QString hex)
{
    emit hexChanged(hex);
}
