#include "settingsviewmodel.h"

settingsViewModel::settingsViewModel(QObject *parent) : QObject(parent), _restHelper(RestHelper::getRestHelper())
{

}

QString settingsViewModel::getUrl()
{
    return _restHelper.getApiUrl();
}

unsigned short settingsViewModel::getPort()
{
    return _restHelper.getPort();
}

void settingsViewModel::setUrl(QString urlStr)
{
    _restHelper.setApiUrl(urlStr);
    emit urlChanged(urlStr);
}

void settingsViewModel::setPort(unsigned short portNum)
{
    _restHelper.setPort(portNum);
    emit portChanged(portNum);
}
