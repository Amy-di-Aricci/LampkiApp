#ifndef SETTINGSVIEWMODEL_H
#define SETTINGSVIEWMODEL_H

#include <QObject>
#include <QString>
#include "Helpers/resthelper.h"
#include <QSettings>

class settingsViewModel : public QObject
{
    Q_OBJECT
    RestHelper& _restHelper;
    QString _ip;
    QSettings _hardDriveSettings;
    unsigned short _port;
    Q_PROPERTY(QString Url READ getUrl WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(unsigned short Port READ getPort WRITE setPort NOTIFY portChanged)
public:
    explicit settingsViewModel(QObject *parent = nullptr);
    QString getUrl();
    unsigned short getPort();
    Q_INVOKABLE QString getUrlFromSettings();
    Q_INVOKABLE unsigned short getPortFromSettings();
    Q_INVOKABLE void setSettings();
signals:
    void urlChanged(QString arg);
    void portChanged(unsigned short arg);

public slots:
    void setUrl(QString urlStr);
    void setPort(unsigned short portNum);
};

#endif // SETTINGSVIEWMODEL_H
