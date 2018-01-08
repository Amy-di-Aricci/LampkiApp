#ifndef RESTHELPER_H
#define RESTHELPER_H

#include <QObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>

class RestHelper : public QObject
{
    Q_OBJECT
    QString apiUrl;
    unsigned short port;
    QNetworkAccessManager manager;
public:
    explicit RestHelper(QObject *parent = nullptr);
    static RestHelper& getRestHelper();
    void SendColor(QJsonDocument jsonDoc, QString api);
    QString getApiUrl();
    void setApiUrl(QString url);
    unsigned short getPort();
    void setPort(unsigned short portNum);
signals:

public slots:
    void fished();
};

#endif // RESTHELPER_H
