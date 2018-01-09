#ifndef RESTHELPER_H
#define RESTHELPER_H

#include <QObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>

/*!
 * \brief The RestHelper class
 * Klasa obsługuje wymianę danych pomiędzy aplikacją a API urządzenia RaspberryPi. Klasa zgodna z wzorcem Singleton
 */
class RestHelper : public QObject
{
    Q_OBJECT
    /*!
     * \brief apiUrl
     * Pole przechowuje adres IP obsługiwanego urządzenia
     */
    QString apiUrl;
    /*!
     * \brief port
     * Pole przechowuje port serwera
     */
    unsigned short port;
    /*!
     * \brief manager
     * Obiekt zarządzający połączeniem z urządzeniem
     */
    QNetworkAccessManager manager;
public:
    explicit RestHelper(QObject *parent = nullptr);
    /*!
     * \brief getRestHelper Zwraca referencję do istniejącego obiektu klasy lub, jeśli nie został wcześniej utworzony, inicjalizuje obiekt klasy RestHelper
     * \return referencja do obiektu klasy RestHelper
     */
    static RestHelper& getRestHelper();
    /*!
     * \brief SendColor Wysyła dokument JSON do urządzenia
     * \param jsonDoc obiekt z danymi w notacji JSON wysyłany do urządzenia
     * \param api fragment adresu URL do API urządzenia
     */
    void SendColor(QJsonDocument jsonDoc, QString api);
    /*!
     * \brief getApiUrl Zwraca adres IP urządzenia RaspberryPi
     * \return QString z adresem IP urządzenia
     */
    QString getApiUrl();
    /*!
     * \brief setApiUrl Modyfikuje adres IP urządzenia
     * \param url łańcuch znaków przypisywany polu apiUrl
     */
    void setApiUrl(QString url);
    /*!
     * \brief getPort Zwraca port połączenia z urządzeniem
     * \return numer portu połączenia
     */
    unsigned short getPort();
    /*!
     * \brief setPort Modyfikuje wartość numeru portu połączenia
     * \param portNum wartość przypisywana polu port
     */
    void setPort(unsigned short portNum);
signals:

public slots:
    /*!
     * \brief fished Obsługuje zdarzenie zakończenia wysyłania danych
     */
    void fished();
};

#endif // RESTHELPER_H
