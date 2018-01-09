#ifndef COLORVIEWMODEL_H
#define COLORVIEWMODEL_H

#include <QObject>
#include <QString>
#include <memory>
#include "Models/acolormodel.h"
#include "Helpers/jsonhelper.h"
#include "Helpers/resthelper.h"

class HSVColorModel;
class RGBColorModel;
/*!
 * \brief The ColorViewModel class
 * Klasa służy do komunikacji między modelami HSVColorModel oraz RGBColorModel a interfejsem użytkownika
 */
class ColorViewModel : public QObject
{
    Q_OBJECT

private:
    /*!
     * \brief _colorModel Polimorficzny obiekt klasy RGBColorModel lub HSVColorModel
     */
    std::unique_ptr<AColorModel> _colorModel;
    /*!
     * \brief _selectedType Pole przechowujące informację na temat wybranej przez użytkownika w UI przestrzeni barw. Jego wartość zależna jest od indeksu wybranego elementu w rozwijanej liście
     */
    int _selectedType;
    Q_PROPERTY(int RH READ GetRH WRITE SetRH NOTIFY RHChanged)
    Q_PROPERTY(int GS READ GetGS WRITE SetGS NOTIFY GSChanged)
    Q_PROPERTY(int BV READ GetBV WRITE SetBV NOTIFY BVChanged)
    Q_PROPERTY(int SelectedType READ getSelectedType WRITE setSelectedType NOTIFY selectedTypeChanged)
    Q_PROPERTY(QString Hex READ GetHex WRITE SetHex NOTIFY hexChanged)

public:
    explicit ColorViewModel(QObject *parent = nullptr);
    /*!
     * \brief GetRH Zwraca wartość składowej Hue lub Red - w zależności od kontekstu
     * \return wartość liczbowa składowej Hue lub Red
     */
    int GetRH();
    /*!
     * \brief GetGS Zwraca wartość składowej Saturation lub Green - w zależności od kontekstu
     * \return wartość liczbowa składowej Saturation lub Green
     */
    int GetGS();
    /*!
     * \brief GetBV Zwraca wartość składowej Value lub Blue - w zależności od kontekstu
     * \return wartość liczbowa składowej Value lub Blue
     */
    int GetBV();
    /*!
     * \brief getSelectedType Zwraca informację o wybranej przestrzeni barw
     * \return wartość liczbowa indeksu wybranego elementu w rozwijanej liście
     */
    int getSelectedType();
    /*!
     * \brief GetHex
     * \return kod szesnastkowy wybranego koloru
     */
    QString GetHex();
    /*!
     * \brief Metoda wysyła dane na temat koloru do urządzenia
     */
    Q_INVOKABLE void SendUnicolor();

signals:
    /*!
     * \brief RHChanged Informuje o zmianie właściwości RH
     * \param arg wartość liczbowa składowej Red lub Hue
     */
    void RHChanged(int arg);
    /*!
     * \brief GSChanged Informuje o zmianie właściwości GS
     * \param arg wartość liczbowa składowej Green lub Saturation
     */
    void GSChanged(int arg);
    /*!
     * \brief BVChanged Informuje o zmianie właściwości BV
     * \param arg wartość liczbowa składowej Blue lub Value
     */
    void BVChanged(int arg);
    /*!
     * \brief selectedTypeChanged Informuje o zmianie wybranej przestrzeni barw
     * \param arg numer indeksu odpowiadającego wybranej przestrzeni barw
     */
    void selectedTypeChanged(int arg);
    /*!
     * \brief hexChanged Informuje o zmianie kodu szesnastkowego koloru
     * \param arg łańcuch znaków z kodem szesnastkowym koloru
     */
    void hexChanged(QString arg);

public slots:
    /*!
     * \brief SetRH Modyfikuje właściwość RH
     * \param rh wartość przypisywana właściwości RH
     */
    void SetRH(int rh);
    /*!
     * \brief SetGS Modyfikuje właściwość GS
     * \param gs wartość przypisywana właściwości GS
     */
    void SetGS(int gs);
    /*!
     * \brief SetBV Modyfikuje właściwość BV
     * \param bv wartość przypisywana właściwości BV
     */
    void SetBV(int bv);
    /*!
     * \brief setSelectedType Modyfikuje właściwość SelectedType, wywołuje konwersję między przestrzeniami HSV i RGB
     * \param selection numer indeksu odpowiadającego wybranej przestrzeni barw
     */
    void setSelectedType(int selection);
    /*!
     * \brief SetHex Modyfikuje właściwość Hex
     * \param hex kod szesnastkowy koloru przypisywany właściwości Hex
     */
    void SetHex(QString hex);
};

#endif // COLORVIEWMODEL_H
