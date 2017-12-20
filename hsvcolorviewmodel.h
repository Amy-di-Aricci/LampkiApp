#ifndef HSVCOLORVIEWMODEL_H
#define HSVCOLORVIEWMODEL_H

#include <QObject>
#include "hsvcolormodel.h"

class HSVColorViewModel : public QObject
{
    Q_OBJECT

private:
    HSVColorModel _colorModel;
    Q_PROPERTY(int Hue READ Hue WRITE setHue NOTIFY HueChanged)
    Q_PROPERTY(int Saturation READ Saturation WRITE setSaturation NOTIFY SaturationChanged)
    Q_PROPERTY(int Value READ Value WRITE setValue NOTIFY ValueChanged)

public:
    explicit HSVColorViewModel(QObject *parent = nullptr);
    int Hue();
    int Saturation();
    int Value();

signals:
    void HueChanged(int arg);
    void SaturationChanged(int arg);
    void ValueChanged(int arg);

public slots:
    void setHue(int h);
    void setSaturation(int s);
    void setValue(int v);
};

#endif // COLORVIEWMODEL_H
