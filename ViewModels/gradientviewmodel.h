#ifndef GRADIENTVIEWMODEL_H
#define GRADIENTVIEWMODEL_H

#include <QObject>
#include <QVector>
#include <QString>
#include <memory>
#include "Models/acolormodel.h"
#include "Models/hsvcolormodel.h"
#include "Models/rgbcolormodel.h"
#include "Helpers/jsonhelper.h"
#include "Helpers/resthelper.h"

/*!
 * \brief The GradientViewModel class
 * Klasa pozwala na obsługę tworzenia gradientu dwukolorowego
 */
class GradientViewModel : public QObject
{
    Q_OBJECT
    /*!
     * \brief _gradientVector Kolekcja przechowująca kody szesnastkowe kolorów
     */
    QVector<QString> _gradientVector;
    /*!
     * \brief _firstColor Polimorficzny obiekt przechowujący początkowy kolor gradientu w przestrzeni HSV lub RGB.
     */
    std::unique_ptr<AColorModel> _firstColor;
    /*!
     * \brief _secondColor Polimorficzny obiekt przechowujący końcowy kolor gradientu w przestrzeni HSV lub RGB.
     */
    std::unique_ptr<AColorModel> _secondColor;
    /*!
     * \brief _selectedDiode Pole przechowujące informację o tym, której diody kolor jest obecnie wybierany
     */
    int _selectedDiode;
    /*!
     * \brief _selectedType Pole przechowujące informację na temat wybranej przez użytkownika w UI przestrzeni barw. Jego wartość zależna jest od indeksu wybranego elementu w rozwijanej liście
     */
    int _selectedType;
    /*!
     * \brief generateGradient Metoda oblicza kolory pośrednie między kolorami granicznymi
     * \return kolekcja kodów szesnastkowych kolorów
     */
    QVector<QString> generateGradient();
    Q_PROPERTY(QVector<QString> gradientVector READ getGradientVector WRITE setGradientVector NOTIFY gradientVectorChanged)
    Q_PROPERTY(int selectedDiode READ getSelectedDiode WRITE setSelectedDiode NOTIFY selectedDiodeChanged)
    Q_PROPERTY(int selectedType READ getSelectedType WRITE setSelectedType NOTIFY selectedTypeChanged)
    Q_PROPERTY(int RH READ GetRH WRITE SetRH NOTIFY RHChanged)
    Q_PROPERTY(int GS READ GetGS WRITE SetGS NOTIFY GSChanged)
    Q_PROPERTY(int BV READ GetBV WRITE SetBV NOTIFY BVChanged)
public:
    explicit GradientViewModel(QObject *parent = nullptr);
    /*!
     * \brief getGradientVector
     * \return kolekcja kodów szesnastkowych kolorów
     */
    QVector<QString> getGradientVector();
    /*!
     * \brief getSelectedDiode
     * \return indeks wybranego końca gradientu
     */
    int getSelectedDiode();
    /*!
     * \brief getSelectedType
     * \return indeks wybranej przestrzeni barw
     */
    int getSelectedType();
    /*!
     * \brief GetRH
     * \return wartość składowej Red lub Hue wybranego końca gradientu
     */
    int GetRH();
    /*!
     * \brief GetGS
     * \return wartość składowej Green lub Saturation wybranego końca gradientu
     */
    int GetGS();
    /*!
     * \brief GetBV
     * \return wartość składowej Blue lub Value wybranego końca gradientu
     */
    int GetBV();
    /*!
     * \brief Metoda wysyła dane na temat wybranych kolorów do urządzenia
     */
    Q_INVOKABLE void SendGradient();
signals:
    /*!
     * \brief gradientVectorChanged Informuje o zmianie elementów kolekcji
     * \param arg kolekcja kodów szesnastkowych kolorów gradientu
     */
    void gradientVectorChanged(QVector<QString> arg);
    /*!
     * \brief selectedDiodeChanged Informuje o zmianie wybranego końca gradientu
     * \param arg indeks wybranego końca gradientu
     */
    void selectedDiodeChanged(int arg);
    /*!
     * \brief selectedTypeChanged Informuje o zmianie wybranej przestrzeni barw
     * \param arg numer indeksu odpowiadającego wybranej przestrzeni barw
     */
    void selectedTypeChanged(int arg);
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
     * \brief selectedTypeChanged Informuje o zmianie wybranej przestrzeni barw
     * \param arg numer indeksu odpowiadającego wybranej przestrzeni barw
     */
    void BVChanged(int arg);
public slots:
    /*!
     * \brief setGradientVector Modyfikuje właściwość gradientVector
     * \param vect kolekcja kodow szesnastkowych kolorów
     */
    void setGradientVector(QVector<QString> vect);
    /*!
     * \brief setSelectedDiode Modyfikuje właściwość selectedDiode
     * \param diode indeks wybieranego końca gradientu
     */
    void setSelectedDiode(int diode);
    /*!
     * \brief setSelectedType Modyfikuje właściwość selectedType, wywołuje konwersję między przestrzeniami HSV i RGB
     * \param selection numer indeksu odpowiadającego wybranej przestrzeni barw
     */
    void setSelectedType(int type);
    /*!
     * \brief SetRH Modyfikuje właściwość RH
     * \param rh wartość przypisywana właściwości RH
     */
    void SetRH(int color);
    /*!
     * \brief SetGS Modyfikuje właściwość GS
     * \param gs wartość przypisywana właściwości GS
     */
    void SetGS(int color);
    /*!
     * \brief SetBV Modyfikuje właściwość BV
     * \param bv wartość przypisywana właściwości BV
     */
    void SetBV(int color);
};

#endif // GRADIENTVIEWMODEL_H
