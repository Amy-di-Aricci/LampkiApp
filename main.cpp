#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "testviewmodel.h"
#include "colorviewmodel.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<TestViewModel>("LampkiApp.TestViewModel", 1, 0, "TestViewModel");
    qmlRegisterType<ColorViewModel>("LampkiApp.ColorViewModel", 1, 0, "ColorViewModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
