#include "jsonhelper.h"
#include <QString>
#include <QJsonDocument>

JSONHelper::JSONHelper()
{

}

JSONHelper &JSONHelper::getJsonHelper()
{
    static JSONHelper jsonHelper;
    return jsonHelper;
}

QJsonDocument JSONHelper::UnicolorToJson(AColorModel& color)
{
    QJsonObject jsonObj;
    jsonObj["color"] = color.AsHex();
    QJsonDocument jsonDoc(jsonObj);
    return jsonDoc;
}

QJsonDocument JSONHelper::MulticolorToJson(QVector<QString> colorArray)
{
    QJsonObject lightsObj;
    for(int i = 0; i<colorArray.length(); i++)
    {
        lightsObj[QString::number(i)] = colorArray[i];
    }
    QJsonObject jsonObj;
    jsonObj["lights"] = lightsObj;
    QJsonDocument jsonDoc(jsonObj);
    return jsonDoc;
}
