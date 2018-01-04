#include "jsonhelper.h"
#include <QString>
#include <QJsonDocument>

JSONHelper::JSONHelper()
{

}

QJsonDocument JSONHelper::UnicolorToJson(AColorModel& color)
{
    QJsonObject jsonObj;
    jsonObj["color"] = color.AsHex();
    QJsonDocument jsonDoc(jsonObj);
    return jsonDoc;
}
