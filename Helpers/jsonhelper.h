#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QVector>
#include <QString>
#include <memory>
#include "Models/acolormodel.h"

/*!
 * \brief The JSONHelper class
 * Klasa przygotowuje dane do przesłania poprzez zapisanie danych na temat ustawionych kolorów diod w JavaScript Object Notation. Klasa jest zgodna z wzorcem Singleton
 */
class JSONHelper
{
public:
    JSONHelper();
    /*!
     * \brief getJsonHelper Zwraca referencję do istniejącego obiektu klasy lub inicjalizuje obiekt klasy JSONHelper, jeśli nie został wcześniej utworzony
     * \return referencja do obiektu klasy JSONHelper
     */
    static JSONHelper& getJsonHelper();
    /*!
     * \brief UnicolorToJson Tworzy JSONa z kolorem wybranym w zakładce "Jeden kolor"
     * \param color referencja do modelu koloru w przestrzeni RGB lub HSV
     * \return QJsonDocument z informacją o pojedynczym kolorze
     */
    QJsonDocument UnicolorToJson(AColorModel& color);
    /*!
     * \brief MulticolorToJson Tworzy JSONa z wieloma kolorami - przypisanymi do każdej diody osobno
     * \param colorArray kolekcja kodów szesnastkowych kolorów
     * \return QJsonDocument z zestawem kolorów
     */
    QJsonDocument MulticolorToJson(QVector<QString> colorArray);
};

#endif // JSONPARSER_H
