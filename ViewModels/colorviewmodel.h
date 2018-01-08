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

class ColorViewModel : public QObject
{
    Q_OBJECT

private:
    std::unique_ptr<AColorModel> _colorModel;
    int _typeSelection;
    Q_PROPERTY(int RH READ GetRH WRITE SetRH NOTIFY RHChanged)
    Q_PROPERTY(int GS READ GetGS WRITE SetGS NOTIFY GSChanged)
    Q_PROPERTY(int BV READ GetBV WRITE SetBV NOTIFY BVChanged)
    Q_PROPERTY(int TypeSelection READ GetTypeSelection WRITE SetTypeSelection NOTIFY typeSelectionChanged)
    Q_PROPERTY(QString Hex READ GetHex WRITE SetHex NOTIFY hexChanged)

public:
    explicit ColorViewModel(QObject *parent = nullptr);
    int GetRH();
    int GetGS();
    int GetBV();
    int GetTypeSelection();
    QString GetHex();
    Q_INVOKABLE void SendUnicolor();

signals:
    void RHChanged(int arg);
    void GSChanged(int arg);
    void BVChanged(int arg);
    void typeSelectionChanged(int arg);
    void hexChanged(QString arg);

public slots:
    void SetRH(int rh);
    void SetGS(int gs);
    void SetBV(int bv);
    void SetTypeSelection(int selection);
    void SetHex(QString hex);
};

#endif // COLORVIEWMODEL_H
