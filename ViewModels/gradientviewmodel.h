#ifndef GRADIENTVIEWMODEL_H
#define GRADIENTVIEWMODEL_H

#include <QObject>
#include <QVector>
#include <QString>
#include <memory>
#include "Models/acolormodel.h"
#include "Models/hsvcolormodel.h"
#include "Models/rgbcolormodel.h"
#include "Helpers/jsonhelper.h"
#include "Helpers/resthelper.h"

class GradientViewModel : public QObject
{
    Q_OBJECT
    QVector<QString> _gradientVector;
    std::unique_ptr<AColorModel> _firstColor;
    std::unique_ptr<AColorModel> _secondColor;
    int _selectedDiode;
    QVector<QString> generateGradient();
    Q_PROPERTY(QVector<QString> gradientVector READ getGradientVector WRITE setGradientVector NOTIFY gradientVectorChanged)
    Q_PROPERTY(int selectedDiode READ getSelectedDiode WRITE setSelectedDiode NOTIFY selectedDiodeChanged)
    Q_PROPERTY(int RH READ GetRH WRITE SetRH NOTIFY RHChanged)
    Q_PROPERTY(int GS READ GetGS WRITE SetGS NOTIFY GSChanged)
    Q_PROPERTY(int BV READ GetBV WRITE SetBV NOTIFY BVChanged)
public:
    explicit GradientViewModel(QObject *parent = nullptr);
    QVector<QString> getGradientVector();
    int getSelectedDiode();
    int GetRH();
    int GetGS();
    int GetBV();
    Q_INVOKABLE void SendGradient();
signals:
    void gradientVectorChanged(QVector<QString> arg);
    void selectedDiodeChanged(int arg);
    void RHChanged(int arg);
    void GSChanged(int arg);
    void BVChanged(int arg);
public slots:
    void setGradientVector(QVector<QString> vect);
    void setSelectedDiode(int diode);
    void SetRH(int color);
    void SetGS(int color);
    void SetBV(int color);
};

#endif // GRADIENTVIEWMODEL_H
