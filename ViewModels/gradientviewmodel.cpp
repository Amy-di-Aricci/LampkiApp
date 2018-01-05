#include "gradientviewmodel.h"

GradientViewModel::GradientViewModel(QObject *parent) : QObject(parent)
{

}

QVector<std::unique_ptr<AColorModel>> GradientViewModel::getGradientVector()
{
    return _gradientVector;
}

void GradientViewModel::setGradientVector(QVector<std::unique_ptr<AColorModel>> vect)
{
    _gradientVector = vect;
    emit gradientVectorChanged(vect);
}
