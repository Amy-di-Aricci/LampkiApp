#include "testviewmodel.h"

TestViewModel::TestViewModel(QObject *parent) : QObject(parent)
{
    _testModel = Test();
}

int TestViewModel::numberValue()
{
    return _testModel.GetNumber();
}

void TestViewModel::setNumberValue(int num)
{
    _testModel.SetNumber(num);
    emit numberValueChanged(num);
}
