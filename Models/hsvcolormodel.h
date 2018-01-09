#ifndef HSVCOLORMODEL_H
#define HSVCOLORMODEL_H

#include "Models/acolormodel.h"
#include <memory>
#include <QString>

class RGBColorModel;

/*!
 * \brief The HSVColorModel class
 * Klasa dziedziczy po abstrakcyjnej klasie AColorModel. Odpowiada za przetwarzanie danych dotyczacych koloru w przestrzeni barw HSV.
 */
class HSVColorModel : public AColorModel
{
    /*!
     * \brief hue
     * Pole przechowuje składową "Hue" (Barwa)
     */
    int hue;
    /*!
     * \brief saturation
     * Pole przechowuje składową "Saturation" (Nasycenie)
     */
    int saturation;
    /*!
     * \brief value
     * Pole przechowuje składową "Value" (Jasność)
     */
    int value;
    /*!
     * \brief ParseToRGB
     * Metoda przelicza składowe z przestrzeni barw HSV do przestrzeni RGB według algorytmu z: https://www.rapidtables.com/convert/color/hsv-to-rgb.html
     * \return unique_ptr do obiektu klasy RGBColorModel
     */
    std::unique_ptr<RGBColorModel> ParseToRGB();

public:
    HSVColorModel();
    /*!
     * \brief HSVColorModel
     * Inicjalizuje obiekt klasy HSVColorModel
     * \param h
     * Wartość do zainicjalizowania pola hue
     * \param s
     * Wartość do zainicjalizowania pola saturation
     * \param v
     * Wartość do zainicjalizowania pola value
     */
    HSVColorModel(int h, int s, int v);
    /*!
     * \brief AsRGB
     * Metoda wywołuje metodę parsującą ParseToRGB() i zwraca wynik konwersji
     * \return unique_ptr do obiektu klasy RGBColorModel
     */
    std::unique_ptr<AColorModel> AsRGB() override;
    /*!
     * \brief AsHSV
     * Metoda przekazuje obiekt klasy HSVColorModel
     * \return unique_ptr do obiektu klasy HSVColorModel
     */
    std::unique_ptr<AColorModel> AsHSV() override;
    /*!
     * \brief AsHex
     * Metoda wykonuje konwersję do modelu RGB, następnie przy użyciu StringStream wartości składowe konwertowane są do systemu heksadecymmalnego oraz łączone w kod szesnastkowy danego koloru.
     * \return QString zawierający kod szesnastkowy koloru
     */
    QString AsHex();

    /*!
     * \brief GetRH
     * \return wartość pola hue
     */
    int GetRH() override;
    /*!
     * \brief GetGS
     * \return wartość pola saturation
     */
    int GetGS() override;
    /*!
     * \brief GetBV
     * \return wartość pola value
     */
    int GetBV() override;
    /*!
     * \brief SetRH Modyfikuje wartość pola hue
     * \param rh Wartość przypisywana składowej hue
     */
    void SetRH(int rh) override;
    /*!
     * \brief SetGS Modyfikuje wartość pola saturation
     * \param gs Wartośc przypisywana składowej saturation
     */
    void SetGS(int gs) override;
    /*!
     * \brief SetBV Modyfikuje wartość pola value
     * \param bv Wartość przypisywana składowej value
     */
    void SetBV(int bv) override;
};

#endif // HSVCOLORMODEL_H
