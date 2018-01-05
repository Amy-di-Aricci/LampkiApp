#ifndef RESTHELPER_H
#define RESTHELPER_H

#include <QObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>

class RestHelper : public QObject
{
    Q_OBJECT
    QString apiUrl;
    QNetworkAccessManager manager;
public:
    explicit RestHelper(QObject *parent = nullptr);
    void SendColor(QJsonDocument jsonDoc);
signals:

public slots:
    void fished();
};

#endif // RESTHELPER_H
