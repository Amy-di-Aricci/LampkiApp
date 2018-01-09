#ifndef RGBCOLORMODEL_H
#define RGBCOLORMODEL_H

#include "Models/acolormodel.h"
#include <QString>
#include <memory>
class HSVColorModel;
/*!
 * \brief The RGBColorModel class
 * Klasa dziedziczy po abstrakcyjnej klasie AColorModel. Odpowiada za przetwarzanie danych dotyczacych koloru w przestrzeni barw RGB.
 */
class RGBColorModel : public AColorModel
{
    /*!
     * \brief red
     * Pole przechowuje składową "Red" (Czerwony)
     */
    int red;
    /*!
     * \brief green
     * Pole przechowuje składową "Green" (Zielony)
     */
    int green;
    /*!
     * \brief blue
     * Pole przechowuje składową "Blue" (Niebieski)
     */
    int blue;
    /*!
     * \brief ParseToHSV
     * Metoda przelicza składowe z przestrzeni barw RGB do przestrzeni HSV według algorytmu z: https://www.rapidtables.com/convert/color/rgb-to-hsv.html
     * \return
     */
    std::unique_ptr<HSVColorModel> ParseToHSV();
public:
    RGBColorModel();
    /*!
     * \brief RGBColorModel
     * Inicjalizuje obiekt klasy RGBColorModel
     * \param r Wartość do zainicjalizowania pola red
     * \param g Wartość do zainicjalizowania pola green
     * \param b Wartość do zainicjalizowania pola blue
     */
    RGBColorModel(int r, int g, int b);
    /*!
     * \brief AsRGB
     * Metoda przekazuje obiekt klasy RGBColorModel
     * \return unique_ptr do obiektu klasy RGBColorModel
     */
    std::unique_ptr<AColorModel> AsRGB() override;
    /*!
     * \brief AsHSV
     * Metoda wywołuje metodę parsującą ParseToHSV() i zwraca wynik konwersji
     * \return unique_ptr do obiektu klasy HSVColorModel
     */
    std::unique_ptr<AColorModel> AsHSV() override;
    /*!
     * \brief AsHex
     * Konwertuje wartości składowe z systemu dziesiątkowego do systemu szesnastkowego przy pomocy StringStream, po czym łączy je w kod szesnastkowy koloru
     * \return QString zawierający kod szesnastkowy koloru
     */
    QString AsHex() override;
    /*!
     * \brief GetRH
     * \return wartość pola red
     */
    int GetRH() override;
    /*!
     * \brief GetGS
     * \return wartość pola green
     */
    int GetGS() override;
    /*!
     * \brief GetBV
     * \return wartość pola blue
     */
    int GetBV() override;
    /*!
     * \brief SetRH Modyfikuje wartość pola red
     * \param rh Wartość przypisywana składowej red
     */
    void SetRH(int rh) override;
    /*!
     * \brief SetGS Modyfikuje wartość pola green
     * \param gs Wartość przypisywana składowej green
     */
    void SetGS(int gs) override;
    /*!
     * \brief SetBV Modyfikuje wartość pola blue
     * \param bv Wartość przypisywana składowej blue
     */
    void SetBV(int bv) override;
};

#endif // RGBCOLORMODEL_H
