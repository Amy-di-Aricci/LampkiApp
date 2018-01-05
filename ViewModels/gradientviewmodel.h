#ifndef GRADIENTVIEWMODEL_H
#define GRADIENTVIEWMODEL_H

#include <QObject>
#include <QVector>
#include <memory>
#include "Models/acolormodel.h"
#include "Models/hsvcolormodel.h"
#include "Models/rgbcolormodel.h"

class GradientViewModel : public QObject
{
    Q_OBJECT
    QVector<std::unique_ptr<AColorModel>> _gradientVector;
    Q_PROPERTY(QVector<std::unique_ptr<AColorModel>> gradientVector READ getGradientVector WRITE setGradientVector NOTIFY gradientVectorChanged)

public:
    explicit GradientViewModel(QObject *parent = nullptr);
    QVector<std::unique_ptr<AColorModel>> getGradientVector();

signals:
    void gradientVectorChanged(QVector<std::unique_ptr<AColorModel>> arg);

public slots:
    void setGradientVector(QVector<std::unique_ptr<AColorModel>> vect);
};

#endif // GRADIENTVIEWMODEL_H
