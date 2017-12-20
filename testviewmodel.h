#ifndef TESTVIEWMODEL_H
#define TESTVIEWMODEL_H

#include <QObject>
#include "test.h"

class TestViewModel : public QObject
{
    Q_OBJECT

private:
    Test _testModel;
    Q_PROPERTY(int numberValue READ numberValue WRITE setNumberValue NOTIFY numberValueChanged)
public:
    explicit TestViewModel(QObject *parent = nullptr);
    int numberValue();

signals:
    void numberValueChanged(int arg);

public slots:
    void setNumberValue(int num);
};

#endif // TESTVIEWMODEL_H
