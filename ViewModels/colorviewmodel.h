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
    Q_PROPERTY(int RH READ GetRH WRITE SetRH NOTIFY RHChanged)
    Q_PROPERTY(int GS READ GetGS WRITE SetGS NOTIFY GSChanged)
    Q_PROPERTY(int BV READ GetBV WRITE SetBV NOTIFY BVChanged)

public:
    explicit ColorViewModel(QObject *parent = nullptr);
    int GetRH();
    int GetGS();
    int GetBV();
    void TypeChange(int selection);

signals:
    void RHChanged(int arg);
    void GSChanged(int arg);
    void BVChanged(int arg);

public slots:
    void SetRH(int rh);
    void SetGS(int gs);
    void SetBV(int bv);
};

#endif // COLORVIEWMODEL_H
