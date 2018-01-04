#ifndef COLORVIEWMODEL_H
#define COLORVIEWMODEL_H

#include <QObject>
#include <memory>
#include "Models/acolormodel.h"

class HSVColorModel;
class RGBColorModel;

class ColorViewModel : public QObject
{
    Q_OBJECT

private:
    std::unique_ptr<AColorModel> _colorModel;
    int _typeSelection;
    Q_PROPERTY(int RH READ GetRH WRITE SetRH NOTIFY RHChanged)
    Q_PROPERTY(int GS READ GetGS WRITE SetGS NOTIFY GSChanged)
    Q_PROPERTY(int BV READ GetBV WRITE SetBV NOTIFY BVChanged)
    Q_PROPERTY(int TypeSelection READ GetTypeSelection WRITE SetTypeSelection NOTIFY TypeSelectionChanged)
    Q_PROPERTY(QString Hex READ GetHex WRITE SetHex NOTIFY HexChanged)

public:
    explicit ColorViewModel(QObject *parent = nullptr);
    int GetRH();
    int GetGS();
    int GetBV();
    int GetTypeSelection();
    QString GetHex();

signals:
    void RHChanged(int arg);
    void GSChanged(int arg);
    void BVChanged(int arg);
    void TypeSelectionChanged(int arg);
    void HexChanged(QString arg);

public slots:
    void SetRH(int rh);
    void SetGS(int gs);
    void SetBV(int bv);
    void SetTypeSelection(int selection);
    void SetHex(QString hex);
};

#endif // COLORVIEWMODEL_H
