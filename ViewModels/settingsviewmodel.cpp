#include "settingsviewmodel.h"

settingsViewModel::settingsViewModel(QObject *parent) : QObject(parent), _restHelper(RestHelper::getRestHelper())
{
    if(_hardDriveSettings.value("ip", "null").toString() == "null")
        _hardDriveSettings.setValue("ip", "192.168.1.6");
    if(_hardDriveSettings.value("port", -1).toInt() == -1)
        _hardDriveSettings.setValue("port", 5000);
    _restHelper.setApiUrl(_hardDriveSettings.value("ip", "192.168.1.6").toString());
    _restHelper.setPort(_hardDriveSettings.value("port", 5000).toInt());
}

QString settingsViewModel::getUrl()
{
    return _ip;
}

unsigned short settingsViewModel::getPort()
{
    return _port;
}

QString settingsViewModel::getUrlFromSettings()
{
    return _hardDriveSettings.value("ip", "192.168.1.6").toString();
}

unsigned short settingsViewModel::getPortFromSettings()
{
    return _hardDriveSettings.value("port", 5000).toInt();
}

void settingsViewModel::setSettings()
{
    _hardDriveSettings.setValue("ip", this->_ip);
    _hardDriveSettings.setValue("port", this->_port);
    _restHelper.setApiUrl(this->_ip);
    _restHelper.setPort(this->_port);
}

void settingsViewModel::setUrl(QString urlStr)
{
    _ip = urlStr;
    emit urlChanged(urlStr);
}

void settingsViewModel::setPort(unsigned short portNum)
{
    _port = portNum;
    emit portChanged(portNum);
}
