#ifndef SETTINGSVIEWMODEL_H
#define SETTINGSVIEWMODEL_H

#include <QObject>
#include <QString>
#include "Helpers/resthelper.h"
#include <QSettings>

/*!
 * \brief The settingsViewModel class Klasa obsługuje komunikację między RestHelperem a UI - pozwala na modyfikację przez użytkownika ustawień połączenia z urządzeniem Raspberry PI.
 */
class settingsViewModel : public QObject
{
    Q_OBJECT
    /*!
     * \brief _restHelper Referencja do singletonowego obiektu klasy RestHelper
     */
    RestHelper& _restHelper;
    /*!
     * \brief _ip Pole przechowujące adres IP obsługiwanego urządzenia
     */
    QString _ip;
    /*!
     * \brief _hardDriveSettings Obiekt służący do odczytu i zapisu ustawień do pliku konfiguracyjnego
     */
    QSettings _hardDriveSettings;
    /*!
     * \brief _port Pole przechowujące port połączenia z urządzeniem
     */
    unsigned short _port;
    Q_PROPERTY(QString Url READ getUrl WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(unsigned short Port READ getPort WRITE setPort NOTIFY portChanged)
public:
    explicit settingsViewModel(QObject *parent = nullptr);
    /*!
     * \brief getUrl
     * \return Zwraca adres IP urządzenia w formie łańcucha znaków
     */
    QString getUrl();
    /*!
     * \brief getPort
     * \return Zwraca port połączenia w formie wartości numerycznej
     */
    unsigned short getPort();
    Q_INVOKABLE QString getUrlFromSettings();
    Q_INVOKABLE unsigned short getPortFromSettings();
    Q_INVOKABLE void setSettings();
signals:
    /*!
     * \brief urlChanged Informuje o zmianie adresu IP przez użytkownika
     * \param arg wpisany przez użytkownika adres IP
     */
    void urlChanged(QString arg);
    /*!
     * \brief portChanged Informuje o zmianie portu przez użytkownika
     * \param arg numeryczna wartość numeru portu
     */
    void portChanged(unsigned short arg);

public slots:
    /*!
     * \brief setUrl Modyfikuje właściwość Url
     * \param urlStr wpisany adres IP
     */
    void setUrl(QString urlStr);
    /*!
     * \brief setPort Modyfikuje właściwość Port
     * \param portNum wpisany numer portu
     */
    void setPort(unsigned short portNum);
};

#endif // SETTINGSVIEWMODEL_H
