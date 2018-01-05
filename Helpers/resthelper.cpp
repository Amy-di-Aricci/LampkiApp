#include "resthelper.h"
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QDebug>

RestHelper::RestHelper(QObject *parent) : QObject(parent), apiUrl(QString("http://192.168.43.177:5000/lights"))
{

}

void RestHelper::SendColor(QJsonDocument jsonDoc)
{
    QNetworkRequest request(QUrl(apiUrl+"/unicolor"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    QNetworkReply* reply = manager.put(request, jsonDoc.toJson(QJsonDocument::Compact));
    connect(reply, SIGNAL(finished()), this, SLOT(fished()));
}

void RestHelper::fished()
{
    qDebug() << "Fished";
}
