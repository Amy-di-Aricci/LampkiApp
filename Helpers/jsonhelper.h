#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QVector>
#include <QString>
#include <memory>
#include "Models/acolormodel.h"

class JSONHelper
{
public:
    JSONHelper();
    static JSONHelper& getJsonHelper();
    QJsonDocument UnicolorToJson(AColorModel& color);
    QJsonDocument MulticolorToJson(QVector<QString> colorArray);
};

#endif // JSONPARSER_H
