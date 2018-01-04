#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonDocument>
#include <memory>
#include "Models/acolormodel.h"

class JSONHelper
{
public:
    JSONHelper();
    QJsonDocument UnicolorToJson(AColorModel& color);
};

#endif // JSONPARSER_H
