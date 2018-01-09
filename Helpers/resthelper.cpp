#include "resthelper.h"
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QDebug>

RestHelper::RestHelper(QObject *parent) : QObject(parent), apiUrl(QString("192.168.1.6")), port(5000)
{

}

RestHelper &RestHelper::getRestHelper()
{
    static RestHelper restHelper;
    return restHelper;
}

void RestHelper::SendColor(QJsonDocument jsonDoc, QString api)
{
    QNetworkRequest request(QUrl("http://"+apiUrl+":"+QString::number(port)+"/lights"+api));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    QNetworkReply* reply = manager.put(request, jsonDoc.toJson(QJsonDocument::Compact));
    connect(reply, SIGNAL(finished()), this, SLOT(fished()));
}

QString RestHelper::getApiUrl()
{
    return apiUrl;
}

void RestHelper::setApiUrl(QString url)
{
    apiUrl = url;
}

unsigned short RestHelper::getPort()
{
    return port;
}

void RestHelper::setPort(unsigned short portNum)
{
    port = portNum;
}

void RestHelper::fished()
{

}
