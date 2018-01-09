#ifndef COLORVIEWMODEL_H
#define COLORVIEWMODEL_H

#include <QObject>
#include <QString>
#include <memory>
#include "Models/acolormodel.h"
#include "Helpers/jsonhelper.h"
#include "Helpers/resthelper.h"

class HSVColorModel;
class RGBColorModel;

class ColorViewModel : public QObject
{
    Q_OBJECT

private:
    std::unique_ptr<AColorModel> _colorModel;
    int _selectedType;
    Q_PROPERTY(int RH READ GetRH WRITE SetRH NOTIFY RHChanged)
    Q_PROPERTY(int GS READ GetGS WRITE SetGS NOTIFY GSChanged)
    Q_PROPERTY(int BV READ GetBV WRITE SetBV NOTIFY BVChanged)
    Q_PROPERTY(int SelectedType READ getSelectedType WRITE setSelectedType NOTIFY selectedTypeChanged)
    Q_PROPERTY(QString Hex READ GetHex WRITE SetHex NOTIFY hexChanged)

public:
    explicit ColorViewModel(QObject *parent = nullptr);
    int GetRH();
    int GetGS();
    int GetBV();
    int getSelectedType();
    QString GetHex();
    Q_INVOKABLE void SendUnicolor();

signals:
    void RHChanged(int arg);
    void GSChanged(int arg);
    void BVChanged(int arg);
    void selectedTypeChanged(int arg);
    void hexChanged(QString arg);

public slots:
    void SetRH(int rh);
    void SetGS(int gs);
    void SetBV(int bv);
    void setSelectedType(int selection);
    void SetHex(QString hex);
};

#endif // COLORVIEWMODEL_H
