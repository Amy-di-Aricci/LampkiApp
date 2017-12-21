#ifndef RGBCOLORVIEWMODEL_H
#define RGBCOLORVIEWMODEL_H

#include <QObject>
#include "rgbcolormodel.h"

class RGBColorViewModel : public QObject
{
    Q_OBJECT

private:
    RGBColorModel _colorModel;
    Q_PROPERTY(int Red READ Red WRITE setRed NOTIFY RedChanged)
    Q_PROPERTY(int Green READ Green WRITE setGreen NOTIFY GreenChanged)
    Q_PROPERTY(int Blue READ Blue WRITE setBlue NOTIFY BlueChanged)

public:
    explicit RGBColorViewModel(QObject *parent = nullptr);
    int Red();
    int Green();
    int Blue();

signals:
    void RedChanged(int arg);
    void GreenChanged(int arg);
    void BlueChanged(int arg);

public slots:
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
};

#endif // RGBCOLORVIEWMODEL_H
