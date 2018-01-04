#ifndef RESTHELPER_H
#define RESTHELPER_H

#include <QObject>
#include <QJsonDocument>

class RestHelper : public QObject
{
    Q_OBJECT
    QString apiUrl;
public:
    explicit RestHelper(QObject *parent = nullptr);
    void SendColor(QJsonDocument jsonDoc);
signals:

public slots:
    void fished();
};

#endif // RESTHELPER_H
